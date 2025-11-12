#include<bits/stdc++.h> 
using namespace std;
string a;
long int b[10000005];
int k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=a.size();
	for(int i=0;i<t;i++){
		if(a[i]-48==0||a[i]-48==1||a[i]-48==2||a[i]-48==3||a[i]-48==4||a[i]-48==5||a[i]-48==6||a[i]-48==7||a[i]-48==8||a[i]-48==9){
			k++;
			b[k]=a[i];
		}	
	}
	sort(b+1,b+k+1);
	for(int i=k;i>0;i--){
		cout<<b[i]-48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
