#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
struct stu{
	int x,y,z;
}s[300005];
bool cmp(stu a,stu b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			s[(j-1)*3+1].x=a[j][1];
			s[(j-1)*3+2].x=a[j][2];
			s[(j-1)*3+3].x=a[j][3];
			s[(j-1)*3+1].y=j;
			s[(j-1)*3+2].y=j;
			s[(j-1)*3+3].y=j;
			s[(j-1)*3+1].z=1;
			s[(j-1)*3+2].z=2;
			s[(j-1)*3+3].z=3;
		}
		if(n<=4){
			sort(s+1,s+1+3*n,cmp);
			int ps=n/2;
			long long max=0;
			for(int h=1;h<=3*n;h++){
				long long sum=0;
				int club[4]={ };
				bool c[300005]={ };
				for(int q=0;q<3*n;q++){
					int j;
					if(q==0){
						j=h;
					}
					else{
						j=q;
						if(q==h){
							j++;
						}
					}
					if(c[s[j].y]==0&&club[s[j].z]<ps){
						sum+=s[j].x;
						c[s[j].y]=1;
						club[s[j].z]++;
					}
				}
				if(sum>=max){
					max=sum;
				}
			}
			cout<<max<<endl;
		}
		else{
			if(a[1][2]==0){
				sort(s+1,s+1+3*n,cmp);
				long long max=0;
				for(int j=1;j<=n/2;j++){
					max+=s[j].x;
				}
				cout<<max<<endl;
			}
			else{
				sort(s+1,s+1+3*n,cmp);
				int ps=n/2;
				long long max=0;
				for(int h=1;h<=3*n;h++){
					long long sum=0;
					int club[4]={ };
					bool c[300005]={ };
					for(int q=0;q<3*n;q++){
						int j;
						if(q==0){
							j=h;
						}
						else{
							j=q;
							if(q==h){
								j++;
							}
						}
						if(c[s[j].y]==0&&club[s[j].z]<ps){
							sum+=s[j].x;
							c[s[j].y]=1;
							club[s[j].z]++;
						}
					}
					if(sum>=max){
						max=sum;
					}
				}
				cout<<max<<endl;	
			}
		}
	}
	return 0;
}
