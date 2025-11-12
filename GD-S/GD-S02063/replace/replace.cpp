#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[200005],b[200005];
int c[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int t1,t2;
		for (int j=1;j<=a[i].size();j++){
			if (a[i][j-1]=='b')t1=j;
			if(b[i][j-1]=='b')t2=j;
		}
		c[i][1]=t1;
		c[i][2]=t2;
		c[i][0]=a[i].size();
	}
	for (int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		int t1,t2,k=0;
		for (int j=1;j<=x.size();j++){
			if (x[j-1]=='b')t1=j;
			if(y[j-1]=='b')t2=j;
			for(int l=1;l<=n;l++){
				if(t1-t2==c[l][1]-c[l][2]&&x.size()-max(t1,t2)>=c[l][0]-max(c[l][1],c[l][2])&&min(t1,t2)>=min(c[l][1],c[l][2])){
					k++;
				}
			}
		}
		cout<<k<<endl;
	}
}
