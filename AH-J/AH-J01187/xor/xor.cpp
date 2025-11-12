#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n, m, a[N], b[N], ans, pot;
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int work(int l, int r){
	if(l==r){
		if(l==m) return 2;
		else return 0;
	}
	for(int i=l; i<=r; i++)
		for(int j=i; j<=r; j++){
			if((b[j]^b[j-1])==m) ans++, i=j+1;
			else if((b[j]^b[i-1])==m){
				if(j-i>0){
					if(l==i&&j==r) {ans++; return 1;}
					else if(work(i, j)==2) ans+=2;
					i=j+1;
				}
				else ans++, i=j+1;
			}
		}
	return ans;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n=read();
	m=read();
	int t=0, tot=0, id=1;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]==m) tot++, pot+=((i==1)?0:work(id, i-1)), id=i+1;
		else b[t]=b[t-1]^a[i], t++;
	}
	cout<<tot+pot+((id>n)?0:work(id, n))<<endl;
	return 0;
}
