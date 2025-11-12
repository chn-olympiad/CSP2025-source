#include<bits/stdc++.h>
using namespace std;
int a[1000005],j=1,numof0=0,num=1;
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int leng=s.size();
//	cout<<leng<<endl;
	for(int i=0;i<leng;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			if(a[j]==0)numof0++;

			j++;
		}
	}

	sort(a+1,a+j+1,cmp);
	sort(a+1,a+j+1,cmp);
	for(int i=j;i>=1;i--){
		if(a[i]!=0)cout<<a[i];
		
	}
	for(int i=1;i<=numof0;i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0; 
} 
