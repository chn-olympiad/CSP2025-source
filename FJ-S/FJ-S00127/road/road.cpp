#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0,nc[1000],gefy,s[10000],c[1000];
struct node{
	int from,to,fy;
}a[100000];
bool cmp(int x,int y){
	if(x<y) return true;
	else return false;
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
	cin>>a[i].from>>a[i].to>>a[i].fy;
	s[i]=a[i].fy;
	}
			sort(s+1,s+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>nc[i]>>a[i].from>>a[i].to>>gefy>>a[i].fy;
		c[i]=a[i].fy;
	} 
	sort(c+1,c+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(s[i]&&s[i]<c[i]){
					sum+=s[i];
					s[i]=false;
			}
			if(c[i]&&c[i]<s[i]){
				sum+=c[i];
				c[i]=false;
			} 
		}
			cout<<sum;
	return 0;
} 
