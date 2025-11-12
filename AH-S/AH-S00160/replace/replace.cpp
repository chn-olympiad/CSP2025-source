#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
string s[N][3],x,y,w1,w2;
int n,q,sum;
int cnt;
struct node{
	string d1,d2,a1,a2;
}d[N];
bool cmp(node a,node b){//checked
	if(a.d1==b.d1)return a.d2<b.d2;
	return a.d1<b.d1;
}
bool operator<(node a,node b){
	if(a.d1==b.d1)return a.d2<b.d2;
	return a.d1<b.d1;
}
bool operator==(node a,node b){
	return a.d1==b.d1&&a.d2==b.d2;
}
bool check1(node a,string d1,string d2){
	if(a.d1==d1)return a.d2<=d2;
	return a.d1<=d1;
}
bool check2(node a,string d1,string d2){
	if(a.d1==d1)return a.d2>=d2;
	return a.d1>=d1;
}
string e1(string s){
	int k=int(s.size());
	s[k-1]=s[k-1]-1;
	return s;
}
void dig(int p){//checked
	int l=-1,r=-1,len=int(s[p][1].size());
	for(int i=0,j=len-1;i<len;i++,j--){
		if(l==-1&&s[p][1][i]!=s[p][2][i])l=i;
		if(r==-1&&s[p][1][j]!=s[p][2][j])r=j;
		if(l!=-1&&r!=-1)break;
	}
	for(int i=l;i<=r;i++)
		d[p].d1+=s[p][1][i],d[p].d2+=s[p][2][i];
	for(int i=0;i<l;i++)d[p].a1+=s[p][1][i];
	for(int i=r+1;i<len;i++)d[p].a2+=s[p][1][i];
}
bool check(node a,string a1,string a2){
	w1=a.a1,w2=a.a2;
	int l1=int(w1.size()),l2=int(w2.size()),r1=int(a1.size()),r2=int(a2.size());
	if(l1>r1||l2>r2)return 0;
	for(int i=l1-1,j=r1-1;i>=0;i--,j--)
		if(w1[i]!=a1[j])return 0;
	for(int i=0,j=0;i<l2;i++,j++)
		if(w2[i]!=a2[j])return 0;
	return 1;
}
void ans(){
	sum=0;
	string d1,d2,a1,a2;
	d1=d2=a1=a2="";
	int l=-1,r=-1,len=int(x.size()),/*mid,*/wl,wr;
	for(int i=0,j=len-1;i<len;i++,j--){
		if(l==-1&&x[i]!=y[i])l=i;
		if(r==-1&&x[j]!=y[j])r=j;
		if(l!=-1&&r!=-1)break;
	}
	for(int i=l;i<=r;i++)
		d1+=x[i],d2+=y[i];
	for(int i=0;i<l;i++)a1+=x[i];
	for(int i=r+1;i<len;i++)a2+=x[i];
	/*l=0,r=len;
	while(l+1<r){
		mid=(l+r)/2;
		if(check1(d[mid],d1,d2))l=mid;
		else r=mid;
	}wl=l;
	l=0,r=len;
	while(l+1<r){
		mid=(l+r)/2;
		if(check2(d[mid],d1,d2))r=mid;
		else l=mid;
	}wr=r;
	 */
	wl=lower_bound(d+1,d+1+n,node{d1,d2,"",""})-d;
	wr=upper_bound(d+1,d+1+n,node{d1,d2,"",""})-d;
	/*
	cout<<"step0 "<<wl<<' '<<wr<<'\n';
	cout<<"step1 "<<d[wl].d1<<' '<<d[wl].d2<<'\n';
	cout<<"step2 "<<d[wr].d1<<' '<<d[wr].d2<<'\n';
	cout<<"step3 "<<d1<<' '<<d2<<"\n\n\n";
	*/
	//for(int i=wl-1;i>=0;i--)if(d[i].d1==d1&&d[i].d2==d2)puts("GSAGAAG");
	for(int i=wl;i<wr;i++){
		if(check(d[i],a1,a2))sum++;
		//if(d[i].d1!=d1||d[i].d2!=d2)puts("SEFDSGAEGAG");
	}
	//sum=wr-wl+1;	
	cout<<sum<<'\n';
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		dig(i);
	}
	sort(d+1,d+1+n,cmp);
	d[n+1].d1=d[n+1].d2="ZZAACZX";
	/*for(int i=1;i<=n;i++){
		cout<<d[i].d1<<' '<<d[i].d2<<'\n';
	}*/
	while(q--){
		cin>>x>>y;
		cnt=0;
		ans();
	}
    return 0;
}
/*
ShanYichun blesses me have over 50pts!!!
*/
