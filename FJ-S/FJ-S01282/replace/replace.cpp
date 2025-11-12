#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int mod1=1000081;
const int mod2=1000919;
const int mod3=1000777;
const int mod4=1000691;
struct nobe{
	int num1,num2,num3,num4;
};
nobe in(){
	char c=getchar();
	int k1=0,k2=0,k3=0,k4=0;
	while(c>='a'&&c<='z'){
		k1=k1*27%mod1+c-'a';
		k2=k2*27%mod2+c-'a';
		k3=k3*27%mod3+c-'a';
		k4=k4*27%mod4+c-'a';
		c=getchar();
	}nobe x={k1,k2,k3,k4};
	return x;
}
int in1(){
	char c=getchar();
	int k=0;
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}return k;
}
void out(int x){
	if(x<10)putchar(x+'0');
	else putchar(x%10+'0'),out(x/10);
}
nobe operator-(nobe x,nobe y){
	nobe ans;
	ans.num1=x.num1-y.num1;
	ans.num2=x.num2-y.num2;
	ans.num3=x.num3-y.num3;
	ans.num4=x.num4-y.num4;
	return ans;
}
nobe operator*(nobe x,int t){
	nobe ans;
	ans.num1=x.num1*t%mod1;
	ans.num2=x.num2*t%mod2;
	ans.num3=x.num3*t%mod3;
	ans.num4=x.num4*t%mod4;
	return ans;
}
int n,q;
bool operator<(nobe x,nobe y){
	if(x.num1!=y.num1)return x.num1<y.num1;
	if(x.num2!=y.num2)return x.num2<y.num2;
	if(x.num3!=y.num3)return x.num3<y.num3;
	return x.num4<y.num4;
}
map<nobe,int>ma;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	n=in1();q=in1();
	for(int i=1;i<=n;i++){
		nobe x=in(),y=in();
		nobe s=x-y;
		for(int j=1;j<=100;j++){
			ma[s]++;
			s=s*27;
		}
	}for(int j=1;j<=q;j++){
		nobe s1=in(),s2=in();
		nobe s=s1-s2;
		cout<<ma[s1-s2]<<'\n';
	}
	return 0;
} 
