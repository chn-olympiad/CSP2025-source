#include<bits/stdc++.h>
using namespace std;
int s[1000024];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a;
    int j=1;
    cin>>a;
    int len=a.size();
    for(int i=0;i<=len;i++){
		if(a[i]>='0' && a[i]<='9'){
			s[j]=a[i]-'0';
			j++;
		}
	}
	j--;
	sort(s+1,s+j+1,cmp);
	for(int i=1;i<=j;i++){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
      
    return 0;
}
