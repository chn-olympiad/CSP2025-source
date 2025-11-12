
#include<bits/stdC++.h>
using namespace std;
int num[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int q=0;
	string a;
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9')num[++q]=(int)a[i]-48;
	}
	sort(num+1,num+q+1,cmp);
	for(int i=1;i<=q;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}

