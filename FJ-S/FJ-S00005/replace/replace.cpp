#include<bits/stdc++.h>
using namespace std;
int b1[214748],b2[214748];
struct se{
	int st,num,ed;
}p[5000000];
bool cmp(se a,se b){
	return a.num<b.num;
}bool check(int s,int a,int b,int nu){
	if(p[s].num!=nu||a<p[s].st||b<p[s].ed)return 0;
	return 1;
}
int bs(int a,int b){
	int l=1,r=b;
	while(l<=r){
		int mid=(l+r)/2;
		if(p[mid].num==a)return mid;
		if(p[mid].num>a)r=mid-1;
		if(p[mid].num<a)l=mid+1;
	}return -1;
}
int main(){
	int a,b;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	string f1,f2;
	for(int i=1;i<=a;i++){
		cin>>f1>>f2;
		int h1=0,h2=0;
		while(f1[h1]=='a')h1++;
		while(f2[h2]=='a')h2++;
		p[i].num=h2-h1;
		p[i].st=h1;
		p[i].ed=f1.size()-p[i].st-1;
	}sort(p+1,p+a+1,cmp);
	for(int i=1;i<=b;i++){
		cin>>f1>>f2;
		int h1=0,h2=0;
		while(f1[h1]=='a')h1++;
		while(f2[h2]=='a')h2++;
		int v=f1.size()-h1-1;
		int g88=h2-h1;
		int re=bs(g88,a);
		if(re==-1){
			cout<<0;
			continue;
		}else{
			int p1=0,m1=re-1,m2=re+1;
			p1+=check(re,h1,v,g88);
			while(m1&&check(m1,h1,v,g88)){
				p1++;
				m1--;
			}while(m2<=a&&check(m2,h1,v,g88)){
				p1++;
				m2++;
			}cout<<p1;
		}
	}
}