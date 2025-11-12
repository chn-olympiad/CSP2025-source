#include<bits/stdc++.h>
using namespace std;

int w,y,h;
int a[10005][10005],qwq[100005];

int main(){
	
	freopen("road.in","r",stdin);
	 freopen("road.out","w",stdout);
	 
	 cin>>w>>y>>h;
	 for (int i=0;i<=y;i++){
	 	int x,q,z;
	 	cin>>x,q;
	 	a[x][q]=a[q][x]=z;
	 } 
	 for(int i=0;i<=h;i++){
	 	int l;
	 	cin>>qwq[i];
	 	for(int j=0;i<=w+1;j++){
	 		cin>>l;
	 		a[w+i][j]=a[j][w+i]=l;
		 }
	 }
	 	for(int i=0;i<=w;i++){
	 		cout<<a<<endl;
   } 
}
