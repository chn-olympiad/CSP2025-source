#include<bits/stdc++.h>
using namespace std;
int max=100005;
int al;
bool d[100005];
int a[100005],b[100005],c[100005];
int as,bs,cs;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","m",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>al;//每组人数 
		for(int j=1;j<=al;j++){
			cin>>a[j]>>b[j]>>c[j];//好感 
		}
		for(int i=1;i<=al/2;i++){
			int lv=1;
			for(int j=1;j<=al;j++){
				if(a[i]<a[j]&&d[j]==0)as+=a[j];a[j]=a[i];lv=0;
			}
			if(lv)as+=a[i];
		}
		cout<<as<<endl;
	}
}
