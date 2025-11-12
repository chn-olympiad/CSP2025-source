#include <bits/stdc++.h>
using namespace std;
inline long long sum_stage(int n){
	long long o = 1;
	for(int i=2;i<=n;i++){
		o*=i;
	}
	return o;
}
inline long long all_permutation(int n, int m){
	return sum_stage(n)/(sum_stage(n-m)*sum_stage(m));
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a, a+n);
	int cnt=0;
	for(int i=3;i<=n;i++){
		const long long permutations = all_permutation(n, i);
		int tmp[i]={};
		iota(tmp, tmp+i, 0);
		for(int j=0;j<permutations;j++){
			for(int mm=i-1;mm>=0;mm--){
				if(tmp[mm]<n+mm-i){
					if (mm==i-1||tmp[mm]+1==n+mm-i) {tmp[mm]++;break;}
					else {
						for(int zz=i-1;zz>mm;zz--){
							tmp[zz]=tmp[zz]-tmp[mm]-(zz-mm-1);
						}
						tmp[mm]++;
						for(int kk=0;kk<i-1;kk++){
							if(tmp[kk]==tmp[kk+1]) tmp[kk]--;
						}
						break;
					}
					
				}
			}
			int M = 0;
			int S = 0;
			for(int nn : tmp){
				S+=a[nn];M=max(M, a[nn]);
			}
			if (S>2*M) cnt++;
		}

	}
	cout<<cnt-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}