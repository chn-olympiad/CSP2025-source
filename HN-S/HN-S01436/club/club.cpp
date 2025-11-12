#include<bits/stdc++.h>
using namespace std;
struct asd{
	int a,b,c;
};
int t;
int n;
int o;
int ans;
asd an[120000];
int am[4][120000];
queue<int> v;
int qwa;
int qwe;
int a[100000];
asd q[10];
int p[4][4];
bool g;
bool cpm(asd a,asd b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qwer=1;qwer<=t;qwer++){
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=3;i++){
			p[1][i]=1;
		}
		for(int i=2;i<=3;i++){
			for(int j=1;j<=3;j++){
				p[i][j]=0;
			}
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>an[i].a>>an[i].b>>an[i].c;
			am[1][i]=an[i].a;
			am[2][i]=an[i].b;
			am[3][i]=an[i].c;
			v.push(i);
		}
		p[2][1]=1900000;
		p[2][2]=1900000;
		p[2][3]=1900000;
		while(v.size()){
			g=0;
			o=v.front();
			q[1].a=an[o].a;
			q[1].b=1;
			q[2].a=an[o].b;
			q[2].b=2;
			q[3].a=an[o].c;
			q[3].b=3;
			sort(q+1,q+4,cpm);
			v.pop();
			for(int i=1;i<=3;i++){
				qwa=q[i].b;
				qwe=q[i].a;
				if(p[1][qwa]==n/2+1){
					if(p[2][qwa]<qwe){
						v.push(p[3][qwa]);
						a[p[3][qwa]]=0;
						a[o]=qwa;
						g=1;
					}else if(p[2][qwa]==qwe){
						if(an[o].a<an[p[3][qwa]].a||an[o].b<an[p[3][qwa]].b||an[o].c<an[p[3][qwa]].c){
							a[p[3][qwa]]=0;
							v.push(p[3][qwa]);
							a[o]=qwa;
							g=1;
						}
					}
					p[2][qwa]=19990999;
					for(int k=1;k<=n;k++){                          
						if(a[k]==qwa){
							if(am[qwa][k]<p[2][qwa]){
								p[2][qwa]=am[qwa][k];
								p[3][qwa]=k;
							}
						}
					}
					if(g){
						break;
					}
				}else{
					if(p[2][qwa]>qwe){
						p[2][qwa]=qwe;
						p[3][qwa]=o; 
					}
					if(p[2][qwa]==qwe){
						if(an[o].a>an[p[3][qwa]].a||an[o].b>an[p[3][qwa]].b||an[o].c>an[p[3][qwa]].c){
							p[2][qwa]=qwe;
							p[3][qwa]=o; 
						}
					}
					a[o]=qwa;
					p[1][qwa]++;
					break;
				}
				 
			}
		}
		for(int i=1;i<=n;i++){
			ans+=am[a[i]][i]; 
		}
		cout<<ans<<endl;
	}
	
} 
