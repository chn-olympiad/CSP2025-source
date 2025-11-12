#include<bits/stdc++.h>
using namespace std;
const int maxa=1e6+10;
int nub[maxa];
int k=0,n,t=0;
int word[maxa];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	/*scanf("%s",word);
	while(word[t]!=' '){
		if(word[t]<='0'&&word[t]>='9'){
			nub[++k]=word[t]-'0';
		}
		t++;
	}*/
	float a;
	/*cin>>a;
	while(a!=' '){
		word[++t]=a;
		cin>>a;
	} */
	cin>>n;
	cout<<n<<endl;
	return 0;
	for(int i=1;i<=maxa;i++){
		cin>>word[i];
		//cout<<word[i];
		t=i;
		if(word[i]==' ')break;
	}
	//for(int i=1;i<=t;i++)cout<<word[i]<<' ';
	for(int i=1;i<=t;i++){
		if(word[i]<='0'  &&  word[i]>=9){
			int n=word[i];
			nub[++k]=n-'0';
		}
	} 
	for(int i=1;i<=k;i++)cout<<nub[i]<<' '; 
	sort(nub+1,nub+k+1);
	for(int i=1;i<=k;i++)printf("%d",nub[i]);
	return 0;
}