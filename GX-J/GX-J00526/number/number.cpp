#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int jl[1000010];
for(int i = 0;i<a.size();i++){
	if(a[i]=='0')
		jl[0]++;
	if(a[i]=='1')
		jl[1]++;
	if(a[i]=='2'){
		jl[2]++;
	}
	if(a[i]=='3')
		jl[3]++;
	if(a[i]=='4')
		jl[4]++;
	if(a[i]=='5')
		jl[5]++;
	if(a[i]=='6')
		jl[6]++;
	if(a[i]=='7')
		jl[7]++;
	if(a[i]=='8')
		jl[8]++;
	if(a[i]=='9')
		jl[9]++;
}
for(int i = 9;i>=0;i--){
	if(jl[i]!=0){
	for(int j = 1;j<=jl[i];j++){
		cout<<i;
	}
}
}
return 0;
}
