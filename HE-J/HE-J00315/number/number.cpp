#include<bits/stdc++.h>
using namespace std;
int n[1000010],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	for(int i=0;i<a.size()-1;i++){
		if((int)a[i]>=48&&(int)a[i]<=57){
			if((int)a[i]==48) n[ans]=0;
			if((int)a[i]==49) n[ans]=1;
			if((int)a[i]==50) n[ans]=2;
			if((int)a[i]==51) n[ans]=3;
			if((int)a[i]==52) n[ans]=4;
			if((int)a[i]==53) n[ans]=5;
			if((int)a[i]==54) n[ans]=6;
			if((int)a[i]==55) n[ans]=7;
			if((int)a[i]==56) n[ans]=8;
			if((int)a[i]==57) n[ans]=9;
			ans++;
		}
	}
	for(int i=0;i<=ans;i++){
		for(int j=0;j<=ans;j++){
			if(n[j]<n[j+1]){
				swap(n[j],n[j+1]);
			}
		}
	}
	for(int i=0;i<=ans;i++){
		cout<<n[i];
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++
