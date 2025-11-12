#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str111;
vector <int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str111;
	int k=str111.size();
	for (int i=0;i<k;i++){
		if (str111[i]>='0' && str111[i]<='9'){
			v.push_back(str111[i]-'0');
		}
	}sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int z=v.size();
	for (int i=0;i<z;i++) cout<<v[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
