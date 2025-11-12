#include<bits\stdc++.h>
using namespace std;

int z[1000005];

int h(int a,int b) {
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int z_i=1;
	cin>>s;
	int n=s.size();
	for (int i=0;i<n;i++) {
		if (s[i]>='0'&&s[i]<='9') {
			z[z_i]=s[i]-'0';
			z_i++;
		}
	}
	sort(z+1,z+z_i,h);
	for (int i=1;i<z_i;i++) {
		cout<<z[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}