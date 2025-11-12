#include<bits/stdc++.h>
using namespace std;
struct sz{
	string a,b,w,v,x1,x2,z1,z2;
};
sz zh(string a,string b){
	sz f;
	bool e=1,u=0;
	f.a=a; f.b=b;
	f.w=""; f.v=""; f.x1=""; f.x2=""; f.z1=""; f.z2="";
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i]&&u){
			f.z1=f.z1+a[i];
			f.z2=f.z2+b[i];
		}else if(a[i]!=b[i]){
			e=0; u=1;
			f.w=f.w+a[i];
			f.v=f.v+b[i];
		}else if(a[i]==b[i]&&e){
			f.x1=f.x1+a[i];
			f.x2=f.x2+b[i];
		}
	}
	return f;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	int n,q,z;
	cin>>n>>q;
	string s[n][2],x,y;
	sz a[q];
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=0;i<q;i++){
		cin>>x>>y;
		a[i]=zh(x,y);
	}
	for(int i=0;i<q;i++){
		z=0;
		for(int j=0;j<n;j++){
			if(a[i].w==s[j][0]&&a[i].v==s[j][1]||a[i].a==s[j][0]&&a[i].b==s[j][1]||a[i].x1==s[j][0]&&a[i].x2==s[j][1]||a[i].z1==s[j][0]&&a[i].z2==s[j][1])z++;
		}
		cout<<z<<endl;
	}
	
	return 0;
}
