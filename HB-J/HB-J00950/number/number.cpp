#include <bits/stdc++.h>
using namespace std;
string a;int t,ab=1;
char q[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	t=a.size();
		for(int i=0;i<t;i++){
		if(a[i]<='9'&&a[i]>='0'){
			q[ab]=a[i];ab++;
			}
		}
		sort(q+1,q+ab+1);
		for(int i=ab;i>=1;i--){
			cout<<q[i];
		}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
	
