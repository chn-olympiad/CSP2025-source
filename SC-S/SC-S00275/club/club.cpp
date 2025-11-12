#include<bits/stdc++.h>
using namespace std;
long long ans=0,sum[4];
struct node{
	long long x,y,z;
	long long mx,id,mxx,idd;
	bool flag;
}a[200010];
bool cmp(node xx,node yy){
	if(xx.mx!=yy.mx)return xx.mx>yy.mx;
	else return xx.mxx>yy.mxx; 
}
int jg;
bool cmp2(node xx,node yy){
	int tmp1=xx.mx,tmp2=yy.mx;
	if(xx.id==jg)tmp1=xx.mxx;
	if(yy.id==jg)tmp2=yy.mxx;
	return tmp1>tmp2; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long tt;
	cin>>tt;
	while(tt--)
	{
		sum[0]=0;sum[1]=0;sum[2]=0;sum[3]=0;
		ans=0;
		long long n;cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].flag=0;
			vector<long long>tmp;
			tmp.push_back(a[i].x);tmp.push_back(a[i].y);tmp.push_back(a[i].z);
			sort(tmp.begin(),tmp.end());
			//cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl; 
			int temp=tmp[1];ans+=temp;
			a[i].x-=temp;a[i].y-=temp;a[i].z-=temp;
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				a[i].mx=a[i].x;a[i].id=1;
				if(a[i].y>=a[i].z){
					a[i].mxx=a[i].y;
					a[i].idd=2;
				}
				else{
					a[i].mxx=a[i].z;
					a[i].idd=3;	
				}
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				a[i].mx=a[i].y;a[i].id=2;
				if(a[i].x>=a[i].z){
					a[i].mxx=a[i].x;
					a[i].idd=1;
				}
				else{
					a[i].mxx=a[i].z;
					a[i].idd=3;	
				}
			}else if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				a[i].mx=a[i].z;a[i].id=3;
				if(a[i].y>=a[i].x){
					a[i].mxx=a[i].y;
					a[i].idd=2;
				}
				else{
					a[i].mxx=a[i].x;
					a[i].idd=1;	
				}
			}
		}
		//cout<<ans<<endl;
		sort(a+1,a+n+1,cmp);
		long long lim=n/2;
		for(long long i=1;i<=n;i++){
			if(sum[a[i].id]<(n/2)){
				a[i].flag=1;
				sum[a[i].id]++;
				ans+=a[i].mx;
				//cout<<a[i].mx<<" ";
			}
			else{
				jg=a[i].id;
				break;
			}
		}
		//cout<<endl;
		sort(a+1,a+n+1,cmp2);
		for(long long i=1;i<=n;i++){
			if(a[i].flag)continue;
			if(a[i].id==jg){
				ans+=a[i].mxx;
				//cout<<a[i].mxx<<" ";
			}
			else{
				ans+=a[i].mx;
				//cout<<a[i].mx<<" ";
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 