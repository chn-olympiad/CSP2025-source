#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=1e5+10;
int n,q,p;
int ans[N];
struct node{
	int id;
	string s1,s2;
}a[N];
void answer(int i,int cnt){
	int sum=0;
	while(1){
		if(a[i].s1!=a[i+1].s1 || a[i].s2!=a[i+1].s2)	break;
		sum++;
		i++;
	}
	ans[cnt]=sum;
	//cout<<i<<endl;
}
bool cmp(node u,node v){
	if(u.s1!=v.s1)	return u.s1<v.s1;
	if(u.s2!=v.s2)	return u.s2<v.s2;
	return u.id>v.id;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=(n+q);i++){
		string x,y;
		cin>>x>>y;
		int len=x.size();
		for(int j=0;j<len;j++)
			if(x[j]!=y[j])	a[i].s1+=x[j],a[i].s2+=y[j];
		if(i<=n)	a[i].id=0;
		else    a[i].id=++p;
	}
	
	sort(a+1,a+(n+q)+1,cmp);
	//for(int i=1;i<=(n+q);i++)
	//	cout<<a[i].s1<<' '<<a[i].s2<<' '<<a[i].id<<endl;
	for(int i=1;i<=(n+q);i++){
		if(a[i].id>=1){
			answer(i,a[i].id);
			//cout<<a[i].id<<endl;
			
		}
		//cout<<i<<endl;
	}
	for(int i=1;i<=q;i++)	cout<<ans[i]<<endl;
	//if(a[5].s1==a[6].s1)	cout<<"jhnvisij";
	return 0;
}
