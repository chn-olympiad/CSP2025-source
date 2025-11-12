#include<bits/stdc++.h>
using namespace std;
int t,n;
int a,b,c;
int num[4],sum[4],m[4][4][100010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum[1]=sum[2]=sum[3]=0;
		num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				num[1]++;
				sum[1]+=a;
				m[1][1][num[1]]=a;
				if(b>=c){
					m[1][2][num[1]]=a-b;
					m[1][3][num[1]]=2;
				}
				else{
					m[1][2][num[1]]=a-c;
					m[1][3][num[1]]=3;
				}
			}
			else if(b>=a&&b>=c){
				num[2]++;
				sum[2]+=b;
				m[2][1][num[2]]=b;
				if(a>=c){
					m[2][2][num[2]]=b-a;
					m[2][3][num[2]]=1;
				}
				else{
					m[2][2][num[2]]=b-c;
					m[2][3][num[2]]=3;
				}
			}
			else{
				num[3]++;
				sum[3]+=c;
				m[3][1][num[3]]=c;
				if(a>=b){
					m[3][2][num[3]]=c-a;
					m[3][3][num[3]]=1;
				}
				else{
					m[3][2][num[3]]=c-b;
					m[3][3][num[3]]=2;
				}
			}
		}
		if(num[1]>n/2){
			sort(m[1][2]+1,m[1][2]+num[1]+1,cmp);
			while(num[1]>n/2){
				sum[1]-=m[1][1][num[1]];
				sum[m[1][3][num[1]]]+=m[1][1][num[1]]-m[1][2][num[1]];
				num[m[1][3][num[1]]]++;
				num[1]--;
			}
		}
		else if(num[2]>n/2){
			sort(m[2][2]+1,m[2][2]+num[2]+1,cmp);
			while(num[2]>n/2){
				sum[2]-=m[2][1][num[2]];
				sum[m[2][3][num[2]]]+=m[2][1][num[2]]-m[2][2][num[2]];
				num[m[2][3][num[2]]]++;
				num[2]--;
			}
		}
		else if(num[3]>n/2){
			sort(m[3][2]+1,m[3][2]+num[3]+1,cmp);
			while(num[3]>n/2){
				sum[3]-=m[3][1][num[3]];
				sum[m[3][3][num[3]]]+=m[3][1][num[3]]-m[3][2][num[3]];
				num[m[3][3][num[3]]]++;
				num[3]--;
			}
		}
		cout<<sum[1]+sum[2]+sum[3]<<'\n';
	}
	return 0;
}
