#include<bits/stdc++.h>
using namespace std;
struct op{
	int x,s;
};
bool cmp(op x,op y)
{
	return (x.x>y.x);
}
int main()
{
freopen("club.in", "r", stdin);
freopen("club.out", "w", stdout);
int t,n,s[100010][4],u[100010];
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>t;
for(int p=1;p<=t;p++){
	cin>>n;
	long long  ans=0;
	vector<int> c1,c2,c3;
	for(int i=1;i<=n;i++){
	cin>>s[i][1]>>s[i][2]>>s[i][3];
	int x=max(s[i][1],max(s[i][2],s[i][3]));
	if(x==s[i][1]){
		c1.push_back(i);u[i]=1;}
	else if(x==s[i][2]){
		c2.push_back(i);u[i]=2;}
	else if(x==s[i][3]){
		c3.push_back(i);u[i]=3;}
    }
    int y=max(c1.size(),max(c2.size(),c3.size()));
    if(y<=n/2){
		for(int i=1;i<=n;i++)
		ans+=s[i][u[i]];
		cout<<ans<<'\n';
		continue;
	}
	else {
		if(y==c1.size()){
			int q=c1.size(),lx=c2.size(),ly=c3.size();
			op hx[c1.size()+1],hy[q+1];
			for(int i=0;i<c1.size();i++){
				int e=c1[i];
				hx[i].x=s[e][2]-s[e][1];
				hy[i].x=s[e][3]-s[e][1];
				hx[i].s=e;
				hy[i].s=e;
			}
			sort(hx,hx+q,cmp);
			sort(hy,hy+q,cmp);
			int r=q,xe=0,ye=0;
			for(int i=0;i<q;i++){
				if(r<=n/2)break;
				else {
					while(u[hx[xe].s]!=1)xe++;
					while(u[hy[ye].s]!=1)ye++;
					int f=max(hx[xe].x,hy[ye].x);
					if(f==hx[xe].x&&lx+1<=n/2){
						lx++;
						u[hx[xe].s]=2;
						r--;
					}
					else {
						ly++;
						u[hy[ye].s]=3;
						r--;
					}
				}
			}
			for(int i=1;i<=n;i++){
		        ans+=s[i][u[i]];}
		        cout<<ans<<'\n';
		        continue;
		}
		else if(y==c2.size()){
			int q=c2.size(),lx=c3.size(),ly=c1.size();
			op hx[c2.size()+1],hy[q+1];
			for(int i=0;i<c2.size();i++){
				int e=c2[i];
				hx[i].x=s[e][3]-s[e][2];
				hy[i].x=s[e][1]-s[e][2];
				hx[i].s=e;
				hy[i].s=e;
			}
			sort(hx,hx+q,cmp);
			sort(hy,hy+q,cmp);
			int r=q,xe=0,ye=0;
			for(int i=0;i<q;i++){
				if(r<=n/2)break;
				else {
					while(u[hx[xe].s]!=2)xe++;
					while(u[hy[ye].s]!=2)ye++;
					int f=max(hx[xe].x,hy[ye].x);
					if(f==hx[xe].x&&lx+1<=n/2){
						lx++;
						u[hx[xe].s]=3;
						r--;
					}
					else {
						ly++;
						u[hy[ye].s]=1;
						r--;
					}
				}
			}
			for(int i=1;i<=n;i++)
		        ans+=s[i][u[i]];
		        cout<<ans<<'\n';
		        continue;
		}
	else if(y==c3.size()){
			int q=c3.size(),lx=c1.size(),ly=c2.size();
			op hx[c3.size()+1],hy[q+1];
			for(int i=0;i<c3.size();i++){
				int e=c3[i];
				hx[i].x=s[e][1]-s[e][3];
				hy[i].x=s[e][2]-s[e][3];
				hx[i].s=e;
				hy[i].s=e;
			}
			sort(hx,hx+q,cmp);
			sort(hy,hy+q,cmp);
			int r=q,xe=0,ye=0;
			for(int i=0;i<q;i++){
				if(r<=n/2)break;
				else {
					while(u[hx[xe].s]!=3)xe++;
					while(u[hy[ye].s]!=3)ye++;
					int f=max(hx[xe].x,hy[ye].x);
					if(f==hx[xe].x&&lx+1<=n/2){
						lx++;
						u[hx[xe].s]=1;
						r--;
					}
					else {
						ly++;
						u[hy[ye].s]=2;
						r--;
					}
				}
			}
			for(int i=1;i<=n;i++)
		        ans+=s[i][u[i]];
		        cout<<ans<<'\n';
		        continue;
		}
		
	}
}


return 0;
}
