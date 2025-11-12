#include<bits/stdc++.h>
using namespace std;
long long ans;
long long I;
long long cur;
long long a[500005];
struct node{
	int start,end;
}b[1000005];
bool cmp(node x,node y){
	if(x.end != y.end)
		return x.end> y.end;
	return x.start < y.start;
}
long long yh(long long x,long long y){
	bool man1[25] = {};
	bool man2[25] = {};
	bool man3[25] = {};
	int i=0,j=0;
	while(x != 0){
		man1[i] = x%2;
		i++;
		x /= 2;
	}
	while(y != 0){
		man2[j] = y % 2;
		j++;
		y/=2;
	}
	for(int i=0;i<max(i,j)-1;i++){
		man3[i] = !(man1[i] == man2[i]);
	}
	long long can = 0;
	for(int i=0;i < max(i,j);i++){
		can += man3[i] * pow(2,i);
	}
	return can;
}
int main(){
	//freopen("r","xor.in",stdin);
	//freopen("w","xor.out",stdout);
	int flag = 1;
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0 && flag != 3){
			 flag = 2;
		}
		else if(a[i] != 0 && a[i] != 1){
			flag = 3;
		}
	}
	if(flag = 1){
		if(k == 1){
			cout << n;
		}
		else if(k == 0){
			cout << n/2;
		}
	}
	else if(flag = 2){
		if(k == 0){
			for(int i=1;i<=n;i++){
				if(a[i] == 0){
					ans++;
				}
				else if(a[i] == 1 && a[i+1] == 1){
					i++;
					ans++;
				}
			}
			cout << ans;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i] == 1){
					ans++;
				}
			}
			cout << ans;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j = i;j<=n;j++){
				if(i == j){
					cur = a[i];
				}
				else{
					cur = yh(a[i],a[i+1]);
					for(int k1 = i+2;k1 <= j;k1++){
						cur = yh(cur,a[k1]);
					}
				}
				if(cur == k){
					b[I].start = i;
					b[I].end = j;
					I++;
				}
			}
		}
		if(I == 0){
			cout << 0 ;
			return 0;
		}
		sort(b,b+I,cmp);
		for(int i=0;i<I;i++){
			ans++;
			if(b[I-1].start < b[i].end){
				cout << ans-1;
				return 0;
			}
			for(int j=i+1;j < I;j++){
				if(b[j].start > b[i].end){
					i = j;
				}
			}
		}
	}
}
