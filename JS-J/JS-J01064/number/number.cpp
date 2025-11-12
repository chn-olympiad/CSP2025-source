#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int q;
	int q1;
	q=a.size();
	for(int i=0; i < q ;i++){
		if(a[i]<='9' && a[i]>='0'){
			p.push_back(a[i]-48);
		}
	}
	sort(p.begin(),p.end());
	q1=p.size();
	for(int i=0;i< q1;i++)cout<<p[q1-1-i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

