#include <iostream>
#include <fstream>
using namespace std;
long long ans=0;
int n;
int *len;
int *ch;
int dt=0;
bool pd(int x){
	int *t=new int[x+1];
	int we=1,sum=0,temp;
	for(int i=1;i<=n;i++) if(ch[i]==1){
		t[we]=len[i];
		sum+=len[i];
		temp==i;
		we++;
	}
	ch[temp]==0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<i;j++)
		if(t[j]>t[j+1]) swap(t[j],t[j+1]);
	}
	if(sum>2*t[x]) return 1;
	return 0;
}
void dfs(int x){
	if(x==dt){
		if(pd(x)) ans++;
		return;
	}
	int c2=0;
	for(int i=1;i<=n;i++){
		if(ch[i]==0){
			ch[i]=1;
			dt++;
			dfs(x);
			dt--;
			ch[i]=2;
			c2++;
		}
	}
	for(int i=n;i>0;i--) if(c2&&ch[i]==2){ch[i]=0;c2--;}
	return;
}
int main(){
	ifstream in("polygon.in");
	ofstream out("polygon.out");
	in>>n;
	len=new int[n+1];
	ch=new int[n+1];
	for(int i=1;i<=n;i++) in>>len[i];
	for(int i=1;i<=n;i++) ch[i]=0;
	for(int i=3;i<=n;i++){
		dfs(i);
	}
	out<<ans%998244353<<endl;
	in.close();
	out.close();
	return 0;
}
