#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int a[266666],j=0;
	while(cin>>s){
		if(s>='1' && s<='9'){
			a[j]=s-48;
			j++;
		}
		if(s==' '){
			break;
		}
	}
	sort(a,a+j);
	for(int i=j-1; i>=0; i--){
		cout<<a[i];
	}
}

/*#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int a[266666],j=0;
	while(cin>>s){
		if(s>='1' && s<='9'){
			a[j]=s-48;
			j++;
		}
		if(s==' '){
			break;
		}
	}
	sort(a,a+j);
	for(int i=j-1; i>=0; i--){
		12312
	}
}*/
