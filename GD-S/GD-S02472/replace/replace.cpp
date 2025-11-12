#include<bits/stdc++.h>
using namespace std;
int n,q;
struct fdjs{
	string a,b;
}s[10500],t[10500];
int dl(string x,string y){
	for(int i=0;i<x.size();i++)
		if(x[i]!=y[i])
			return i;
	return 0;
}
int dr(string x,string y){
	for(int i=x.size()-1;i>=0;i--)
		if(x[i]!=y[i])
			return i;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++)
		cin>>t[i].a>>t[i].b;
	for(int i=1;i<=q;i++){
		int cnt=0;
		if(t[i].a.size()==t[i].b.size()){
			int l=dl(t[i].a,t[i].b),r=dr(t[i].a,t[i].b);
			for(int j=1;j<=n;j++){
				if(s[j].a.size()<=t[i].a.size()&&s[j].a.size()>=r-l+1){
					int x=r-s[j].a.size()+1;
					if(x<0)
						x=0;
					int w1=t[i].a.find(s[j].a,x),w2=t[i].b.find(s[j].b,x);
					if(w1==w2&&w1<=l&&w1>=0){
						cnt++;
					}else if(w1<=l&&w1>=0&&w2<=l&&w2>=0){
						if(w1>w2){
							if(t[i].b.find(s[j].b,w1)==w1)
								cnt++;
						}else
							if(t[i].a.find(s[j].a,w2)==w2)
								cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
