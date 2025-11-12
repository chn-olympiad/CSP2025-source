#include<bits/stdc++.h>
using namespace std;
struct o{
int x,y,z,max;
}a[100010];
bool cmp(o a,o b){
	return a.max>b.max;	
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
	int T;
	cin>>T;
	for(int j=1;j<=T;j++){
		int n,s,k,b,c;
		s=k=b=c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].max=a[i].x>a[i].y?a[i].x>a[i].z?a[i].x:a[i].z:a[i].y>a[i].z?a[i].y:a[i].z;		
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].max==a[i].x&&k<n/2){
				k++;
				s+=a[i].x;
			}
			else if(a[i].max==a[i].y&&b<n/2){
				b++;
				s+=a[i].y;
			}
			else if(a[i].max==a[i].z&&c<n/2){
				c++;
				s+=a[i].z;
			}
			else{
				int t,u,q;
				t=u=q=0;
				if(k<n/2)t=a[i].x;
				if(b<n/2)u=a[i].y;
				if(c<n/2)q=a[i].z;
				int f=t>u?t>q?t:q:u>q?u:q;
				if(f==t){
					k++;	
				}
				else if(f==u)b++;
				else c++;
				s+=f;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
