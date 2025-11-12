#include<bits/stdc++.h>
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
using namespace std;
const int N=105;
int n,m,a[N],f;
pair<int,int>now; 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	fre("seat");
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int r=a[0],p;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(r==a[i]){p=i;break;}
	}
	now={0,0};f=1;
	for(int i=0;i<n*m;i++){
		if(now.first<n-1&&f==1)now.first++;
		else if(now.first>0&&f==0)now.first--;
		else if(f==1)now.second++,f=0;
		else now.second++,f=1;
		if(--p==0)break;
	}
	cout<<now.second+1<<" "<<now.first+1<<"\n";
	return 0;
}