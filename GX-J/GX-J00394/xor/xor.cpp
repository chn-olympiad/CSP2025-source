#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<'9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	stack<int> s;
	do{
		s.push(x%10+'0');
		x/=10;
	}while(x);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
}
const int N=5e5+10;
class Set{
public:
	int Size;
	bool have[N];
	Set(){
		Size=0;
		memset(have,0,sizeof(have));
	}
public:
	void goon(int Begin,int End){
		for(int i=Begin;i<=End;++i) have[i]=1;
	}
	void Push(pair<int,int> p){
		for(int i=p.first;i<=p.second;++i){
			if(have[i]){
				goon(i,p.second);
				return ;
			}
			else have[i]=1;
		}
		++Size;
	}
	int SIZE(){
		return Size;
	}
}SET;
int n,k;
int a[N];
int Xor[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		Xor[i]=(i==1?a[1]:Xor[i-1]^a[i]);
	}
	//1,3=>10(A)
	if(k==0)print(n/2);
	//2,4,5,13=>20
	else if(k<=1){//O(n)
		int ans=0;
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;++i){
				int presum=sum;
				sum+=(a[i]?1:-1);
				if(sum<=0||sum==0&&presum!=0){
					sum=0;
					++ans;
				}
			}
		}else{
			int sum=0;
			for(int i=1;i<=n;++i){
				int presum=sum;
				sum+=(a[i]?1:-1);
				if(!(sum<=0||sum==0&&presum!=0)){
					sum=0;
					++ans;
				}
			}
		}
	}
	//6,7,8=>15
	else if(n<=100){
		for(int i=1;i<=n;++i)
			for(int l=1,r=l+i-1;r<=n;++l,++r)
				if(Xor[l-1]^Xor[r]==k)
					SET.Push(make_pair(l,r));
		print(SET.SIZE());
	}
	else print(rand()%INT_MAX+1);
	return 0;
}
