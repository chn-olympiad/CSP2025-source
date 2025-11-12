#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
	string a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int r=a.size();
	for(int i=0;i<r;i++){
		if(a[i]=='0')ans[0]+=1;
		if(a[i]=='1')ans[1]+=1;
		if(a[i]=='2')ans[2]+=1;
		if(a[i]=='3')ans[3]+=1;
		if(a[i]=='4')ans[4]+=1;
		if(a[i]=='5')ans[5]+=1;
		if(a[i]=='6')ans[6]+=1;
		if(a[i]=='7')ans[7]+=1;
		if(a[i]=='8')ans[8]+=1;
		if(a[i]=='9')ans[9]+=1;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ans[i];j++)cout<<i;
	}
	return 0;
}//666h6hhbnb67bn67b8b t76 788797979998778778778
