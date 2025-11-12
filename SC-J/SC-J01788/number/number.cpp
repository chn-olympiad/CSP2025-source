#include <bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int j=0;
	for(int i=0;i<n.size();i++){
		if(n[i]=='0'){
			j++;
			a[j]=0;
			
		}else if(n[i]=='1'){
			j++;
			a[j]=1;
			
		}else if(n[i]=='2'){
			j++;
			a[j]=2;
			
		}else if(n[i]=='3'){
			j++;
			a[j]=3;
			
		}else if(n[i]=='4'){
			j++;
			a[j]=4;
			
		}else if(n[i]=='5'){
			j++;
			a[j]=5;
		}else if(n[i]=='6'){
			j++;
			a[j]=6;
			
		}else if(n[i]=='7'){
			j++;
			a[j]=7;
			
		}else if(n[i]=='8'){
			j++;
			a[j]=8;
			
		}else{
			if(n[i]=='9'){
				j++;
				a[j]=9;
				
			} 
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}