#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m,c,r,num=0,ans=1,R;
int s1[N],s2[N],s3[N],s4[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>s1[i];
	R=s1[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(s1[num]<=s1[j])num=j;
			}
		s2[i]=s1[num];
		s1[num]=0;
	}
	for(int i=1;i<=n*m;i++){
		s3[i-1]=i%n;
		if(i%n==0)s3[i-1]=n;
		s4[i-1]=s3[i-1];
		}
	for(int i=0;i<=n*m;i++){
		if(s3[i]==n){
			for(int j=i+1;j<i+5;j++){
				num=s4[j];
				s4[j]=n-num+1;
				}
			}
		}
	for(int i=0;i<n*m;i++){
		if(s2[i]==R)cout<<ans<<" "<<s4[i];
		if(s3[i]==n)ans+=1;
		}
}

