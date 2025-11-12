#include <bits/stdc++.h>
using namespace std;

//xor 相同为0，不同为1 

struct node{
	int u,l;
};
const int N=5e5+5;
int n,k,c;
int a[N],b[N];
queue<node> q;

string x_2(int x){
	string s="",t="";
	while(x){
		t+=(x%2+'0');
		x/=2;
	}
	for(int i=t.size()-1;i>=0;i--){
		s+=t[i];
	}
	return s;
}
int x_10(string x){
	int s=0;
	for(int i=0;i<x.size();i++){
		s=s*2+(x[i]-'0');
	}
	return s;
}

string xor_2(string x,string y){
	string x1="",y1="",z1="",z="";
	for(int i=x.size()-1;i>=0;i--){
		x1+=x[i];
	}
	for(int i=y.size()-1;i>=0;i--){
		y1+=y[i];
	}
	
	if(x1.size()<y1.size()){
		for(int i=0;i<x1.size();i++){
			if(x1[i]==y1[i])z1+='0';
			else z1+='1';
		}
		for(int i=x1.size();i<y1.size();i++){
			z1+=y1[i];
		}
	}else{
		for(int i=0;i<y1.size();i++){
			if(x1[i]==y1[i])z1+='0';
			else z1+='1';
		}
		for(int i=y1.size();i<x1.size();i++){
			z1+=x1[i];
		}
	}
	
	for(int i=z1.size()-1;i>=0;i--){
		z+=z1[i];
	}
	return z;
}

bool check(int x,int y){
	string x1=x_2(x),y1=x_2(y);
	string z1=xor_2(x1,y1);
	int z=x_10(z1);
	return z==k;
}

void bfs(){
	while(!q.empty()){
		node t=q.front();
		q.pop();
		if(check(b[t.u-1],b[t.u+t.l-1]) && a[t.u]!=-1 && a[t.u+t.l-1]!=-1){
			c++;
			for(int i=t.u;i<=t.u+t.l-1;i++){
				a[i]=-1;
			}
		}else if(a[t.u+t.l]!=-1 && t.u+t.l<=n && a[t.u]!=-1 && a[t.u+t.l-1]!=-1){
			q.push({t.u,t.l+1});
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		string x=x_2(b[i-1]),y=x_2(a[i]);
		string z=xor_2(x,y);
		b[i]=x_10(z);
	}
	
	for(int i=n;i>=1;i--){
		q.push({i,1});
	}
	bfs();
	
	cout<<c;
	return 0;
} 
