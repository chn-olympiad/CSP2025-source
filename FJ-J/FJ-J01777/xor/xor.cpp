#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5;
const int MAX=1<<20;
int n,k,a[MAXN];
int s[MAXN],s_9178[MAXN];
vector<int> ve[MAX];

char gc(){return getchar();}
void pc(char c){putchar(c);}

void read(int &x){
	char c; bool f=false;
	for(;!isdigit(c=gc());)
		if(c=='-') f=true;
	for(x=c-'0';isdigit(c=gc());)
		x=x*10+c-'0';
	if(f) x=-x;
}

void write(int x){
	if(x==0){pc('0');return;}
	if(x<0){pc('-');x=-x;}
	char s[20]; int len=0;
	for(;x;x/=10) s[len++]=x%10+'0';
	for(;len--;) pc(s[len]);
}

void input(){
	read(n),read(k);
	for(int i=1;i<=n;++i) read(a[i]);
}

bool check1(){//A
	for(int i=1;i<=n;++i) if(a[i]!=1) return false;
	return k==0;
}

bool check2(){//B
	for(int i=1;i<=n;++i) if(a[i]!=0&&a[i]!=1) return false;
	return k==0||k==1;
}

void solve1(){
	int ans=n/2;
	write(ans);
}

void solve2(){
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;++i){
			if(a[i]==0) ++ans;
			if(a[i]==1&&a[i-1]==1) ++ans,++i;
		}
	}else{
		for(int i=1;i<=n;++i){
			if(a[i]==1) ++ans;
		}
	}
	write(ans);
}

int find(int x,int k){
	int l=0,r=ve[k].size()-1,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ve[k][mid]>x) r=mid-1,ans=ve[k][mid];
		else l=mid+1;
	}
	return ans;
}

void solve3(){
	s[0]=0;
	for(int i=1;i<=n;++i)	s[i]=s[i-1]^a[i];
	for(int i=0;i<=n;++i) s_9178[i]=s[i]^k;
	for(int i=0;i<=n;++i)	ve[s[i]].push_back(i);
	for(int i=0;i<MAX;++i) sort(ve[i].begin(),ve[i].end());
	
	int ans=0;
	for(int i=0,lst=0;i<=n&&lst<n;++i){
		int p=find(lst,s_9178[i]);
		if(p!=-1&&p>i&&p>lst){
			++ans;
//			cout<<"find: "<<lst+1<<"--"<<p<<"\n";
			lst=p;
		}
	}
	write(ans);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	input();
	if(check1()) solve1();
	else if(check2()) solve2();
	else solve3();
	return 0;
}
