#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int pr[1000005],t=0;
	char a[1000005];
	cin>>a;
	int n=strlen(a);
	//cout<<n<<"/n";
	for(int i=0;i<n;i++){
		if(a[i]>='0' and a[i]<='9'){
			pr[t]=a[i]-'0';
			t++;
			//cout<<pr[t-1];
		}
	}
	//cout<<t<<' '<<n;
	sort(pr,pr+t,cmp);
	for(int i=0;i<t;i++){
		cout<<pr[i];
	}
	fclose(stdin);
	fclose(stdout);
} 
