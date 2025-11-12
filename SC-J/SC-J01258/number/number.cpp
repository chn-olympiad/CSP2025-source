#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string m;
	int sum=0;
	int a[m.length()+1];
    cin>>m;
    for(int i=0;i<m.length();i++){
      if(m[i] >= '0' && m[i]<='9'){
      	a[sum] = m[i];
      	sum++;
}
}

sort(a,a+sum+1);
for(int j=sum-1;j>=0;j--){
	cout<<a[j];
}

return 0;	
	

}
