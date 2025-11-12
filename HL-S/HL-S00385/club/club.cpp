#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=1e5+10;
int a[N][5];
int v[5];
int f(int dep){
	if(dep==n+1) return 0;
	int ans=-1;
	for(int i=1;i<=3;i++){
		if(v[i]>=n/2) continue;
		v[i]++;
		ans=max(ans,a[dep][i]+f(dep+1));
		v[i]--;
	} 
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		v[1]=v[2]=v[3]=0;
		int sum=0;
		int b[N];
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i]=a[i][1];
			if(a[i][2]!=0) f1=1;
			if(a[i][3]!=0) f2=1;
		}
		if(f1==0 && f2==0){
			sort(b+1,b+n+1);
			for(int j=n;j>=n/2;j--){
				sum+=b[j];
			}
			cout <<sum;
			continue;
		}
		cout << f(1) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

