#include <bits/stdc++.h> 
using namespace std;
int n,m,ansa,ansb,ansc,sum;
struct node{
	int a,b,c;
}p[100005];
bool cmp(node i,node j){
	if(i.a==j.a){
		if(i.b==j.b){
			return i.c>j.c;
		}
		else return i.b>j.b;
	}
	else return i.a>j.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>p[j].a>>p[j].b>>p[j].c;
		}
		sort(p+1,p+1+m,cmp);
		for(int k=1;k<=m;k++){
			int ma=max(p[k].a,max(p[k].b,p[k].c));
			if(ma==p[k].a&&ansa<=m/2){
				sum+=p[k].a;
				ansa++;
			}
			else if(ma==p[k].b&&ansb<=m/2){
				sum+=p[k].b;
				ansb++;
			}
			else if(ma==p[k].c&&ansc<=m/2){
				sum+=p[k].c;
				ansc++;
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

