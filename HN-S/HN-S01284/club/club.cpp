#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[3],x[MAXN];
priority_queue<int> q[3];
int b[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0,t=0,flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[0]>>a[1]>>a[2];
			sort(a,a+3);
			if(a[0]==0&&a[1]==0){
				x[++t]=a[2];
				flag=1;
			}
			if(flag==0){
				sum+=a[2];
			}
		}
		if(flag==1){
			sort(x+1,x+n+1);
			for(int i=n,j=1;i>=1,j<=n/2;i--,j++){
				sum+=x[i];
			}
		}
		cout<<sum<<endl;
	}
}

