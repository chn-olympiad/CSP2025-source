#include<bits/stdc++.h>
using namespace std;
int const N=5e6+1;
string a[N],b[N];
string s,t;
int n,q,ans;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void read_str(string &S){
	S="";
	char ch=getchar();
	while(!isalpha(ch)){
		ch=getchar();
	}
	while(isalpha(ch)){
		S+=ch;
		ch=getchar();
	}
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void work(string &S){
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			continue;
		}
		int tp=S.find(a[i]);
		if(tp==S.size()){
			continue;
		}
		string temp=S;
		for(int j=0;j<a[i].size();j++){
			temp[tp+j]=b[i][j];
		}
		if(temp==t){
			ans++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		read_str(a[i]);
		read_str(b[i]);
	}
	while(q--){
		ans=0;
		read_str(s);
		read_str(t);
		if(s.size()!=t.size()){
			ans=0;
		}
		else{
			work(s);
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}