#include<bits/stdc++.h>//0
#define int long long
using namespace std;
void read(int &x){
	x=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
void read(string &str){
	str="";
	char ch=getchar();
	while(ch<'!'||ch>'~')ch=getchar();
	while(ch>='!'&&ch<='~')str+=ch,ch=getchar();
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}
void write(string str){
	for(int i=0;i<str.size();i++)putchar(str[i]);
}
void write(const char ch[]){
	for(int i=0;i<strlen(ch);i++)putchar(ch[i]);
}
template<typename o,typename...c>
void read(o &a,c&...b){
	read(a);
	read(b...);
}
template<typename o,typename...c>
void write(o a,c...b){
	write(a);
	write(b...);
}
int T,n,i,sum;
typedef pair<int,int> ppp;
priority_queue<ppp,vector<ppp>,greater<ppp> >pa,pb,pc;
struct node{
	int a,b,c;
}a[100100];
bool cmp(node a,node b){
	if(a.a==b.a){
		if(a.b==b.b)return a.c>b.c;
		return a.b>b.b;
	}
	return a.a>b.a;
}
void add(int i,bool va,bool vb,bool vc){
	if((a[i].a>a[i].b||vb)&&(a[i].a>a[i].c||vc)&&!va){
		if(pa.size()<n/2)pa.push((ppp){a[i].a,i});
		else{
			ppp tp=pa.top();
			if(tp.first<a[i].a){
				pa.pop();
				pa.push((ppp){a[i].a,i});
				add(tp.second,true,false,false);
			}else add(i,true,vb,vc);
		}
	}
	if((a[i].b>a[i].a||va)&&(a[i].b>a[i].c||vc)&&!vb){
		if(pb.size()<n/2)pb.push((ppp){a[i].b,i});
		else{
			ppp tp=pb.top();
			if(tp.first<a[i].b){
				pa.pop();
				pa.push((ppp){a[i].b,i});
				add(tp.second,false,true,false);
			}else add(i,va,true,vc);
		}
	}
	if((a[i].c>a[i].b||vb)&&(a[i].c>a[i].a||va)&&!vc){
		if(pc.size()<n/2)pc.push((ppp){a[i].c,i});
		else{
			ppp tp=pc.top();
			if(tp.first<a[i].c){
				pc.pop();
				pc.push((ppp){a[i].c,i});
				add(tp.second,false,false,true);
			}else add(i,va,vb,true);
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(i=1;i<=n;i++)read(a[i].a,a[i].b,a[i].c);
		sum=0;
		for(i=1;i<=n;i++){
			add(i,false,false,false);
		}
		while(pa.size())sum+=pa.top().first,pa.pop();
		while(pb.size())sum+=pb.top().first,pb.pop();
		while(pc.size())sum+=pc.top().first,pc.pop();
		write(sum,"\n");
	}
	return 0;
}
/*
 \   _  v  _    v   \   /    \   _               /  _     v  _  /  _  /   /   \   v    /   /    _
da jia hao a , wo shi qian mian de HN-J01615 , chu fei J zu de qi pa xin wei da shang hai mei chu
 /   _    _  _    v  v   /   /   v    \    _  _    v  v      _
wan le , t* m* S zu yi qian mei kao guo , gu fen zhi you 90 fen

luogu:MCbucket

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
