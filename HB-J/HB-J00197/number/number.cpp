#include<bits/stdc++.h>
#include<cstring>
using namespace std;

    int l=1;
	int j=1,b[1000001];
	
	bool cmp(int x,int y){
	return x>y;
	}

int main(){
	string a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	//cout<<l<<" ";
	for(int i=0;i<=l;i++){
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
		{   
			b[j]=a[i]-48;
			//cout<<b[j]<<endl;
			j++;
		}
	} 
	
	sort(b+1,b+j,cmp);
	for(int i=1;i<=j-1;i++){cout<<b[i];}
	return 0;
}
	
