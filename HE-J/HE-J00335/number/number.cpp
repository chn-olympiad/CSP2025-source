#include<bits/stdc++.h>
using namespace std;
bool cmp(int bb,int b){
	if(bb>b){
		return b>bb;
	}
}
int j[100006];
int y,jlong;
string a;
int ji;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int kk=a.size();
	for(int i=0;i<kk;i++){
		if(a[i]-48>0&&a[i]-48<=9){
			j[y]=a[i];
			j[y]-=48;
			y++;
			ji++;
		}
		if(a[i]-48==0){
			jlong++;
		}
	}
	sort(j,j+ji,cmp);
	for(int i=ji-1;i>=0;i--){
		cout<<j[i];
	}
	for(int i=0;i<jlong;i++){
		cout<<"0";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
