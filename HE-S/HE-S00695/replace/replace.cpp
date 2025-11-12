#include <bits/stdc++.h>
using namespace std;
int n,m,k;
string a[911][3],b[7878][3];
	bool comp(int x,int y,string s){
		bool f=1;
		for(int i=1,j=x;i<s.length(),
		j<=y;i++,j++){
			if(b[x][y]=s[y])
				f=0;
	}
	return f;
}
	void swaps(int x,int y,int l,int r,string s;){
		for(int i=0,j=l;i<s.length(),j<=r;j++,i++){
			b[x][y][j]=s[i];
		}
	}
	bool comp(int x,int y,string s){
	bool f=1;
	if(x.length()=y.lenth())
		f=0;
	for(int i=1,j=x;i<s.length(),j<=y;i++,j++){
		if(x[i]=y[i])
		f=0;
	}
	return f;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i][0]<<b[i][1];
	}
	for(int i=1;i<=m;i++){
		if(b[i][0].length!=b[i][1].length)
		continue;
		else{
			for(int l=1;l<=n;l++){
				for(int r=l;r<=n;j++){
					if(comp(i,0,l,r,a[j][0]))
						swaps(i,0,r,a[j][l])
					if(comp(b[i][0],b[i][1]))
				}
			}
		}
	} 

	return 0;
}
