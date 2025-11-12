#include <bits/stdc++.h>

using namespace std;
struct node {
	string a;
	string b;
};
node s[200100];
node t[200100];
int t1[200100];
int t2[200100];
int t3[200100];
int t4[200100];
//bool B=true;
//int check_b[200100][4];
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>s[i].a>>s[i].b;
	}
	for(int i=0; i<q; i++) {
		cin>>t[i].a>>t[i].b;
	}
	if(n>10000 || q>10000) {
		//B:
//		for(int i=0; i<n; j++) {
//			for(int j=0; j<s[i].a.size()) {
//				if(s[i].a[j]=='b') {
//					t1[i]=j;
//					break;
//				}
//			}
//			for(int j=0; j<s[i].b.size()) {
//				if(s[i].b[j]=='b') {
//					t2[i]=j;
//					break;
//				}
//			}
//		}
//		for(int i=0; i<q; j++) {
//			for(int j=0; j<t[i].a.size()) {
//				if(t[i].a[j]=='b') {
//					t2[i]=j;
//					break;
//				}
//			}
//			for(int j=0; j<t[i].b.size()) {
//				if(t[i].b[j]=='b') {
//					t3[i]=j;
//					break;
//				}
//			}
//		}
//		for(int i=0;i<q;i++){
//			
//		}
		for(int i=0;i<q;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	for(int i=0; i<q; i++) { //deal with each questins
//		printf("Dealing with question %d\n",i);
		int ans=0;
		if(t[i].a.size()!=t[i].b.size()) {
//			printf("Size of string a and b is not same.answer is 0.\n");
			cout<<0<<endl;
			continue;
		}
		for(int j=0; j<n; j++) { //choose every s
//		printf("Trying s[%d]:%s ; %s\n",j,s[j].a.c_str(),s[j].b.c_str());
			for(int l=0; l+s[j].a.size()-1<t[i].a.size(); l++) {
//				printf("Left of the translate is %d\n",l);
				int r=l+s[j].a.size()-1;
//				printf("Right of the translate is %d\n",r);
//				for(int k=0;k<l;k++){
//					cout<<t[i].a[k];
//				}
//				cout<<"|";
//				for(int k=l;k<=r;k++){
//					cout<<t[i].a[k];
//				}
//				cout<<"|";
//				for(int k=r+1;k<t[i].a.size();k++){
//					cout<<t[i].a[k];
//				}
//				cout<<"->";
//				for(int k=0;k<l;k++){
//					cout<<t[i].a[k];
//				}
//				cout<<"|";
//				for(int k=l,m=0;k<=r;k++,m++){
//					cout<<s[j].b[m];
//				}
//				cout<<"|";
//				for(int k=r+1;k<t[i].a.size();k++){
//					cout<<t[i].a[k];
//				}
//				cout<<endl;
//				cout<<"Translater: ";
//				for(int k=0;k<s[j].a.size();k++){
//					cout<<s[j].a[k];
//				}
//				cout<<"->";
//				for(int k=0;k<s[j].b.size();k++){
//					cout<<s[j].b[k];
//				}
//				cout<<endl<<" compare with ";
//				for(int k=0;k<t[i].b.size();k++){
//					cout<<t[i].b[k];
//				}
//				cout<<endl;
				bool pd2=true;
				for(int k=0; k<s[j].a.size(); k++) {
					if(s[j].a[k]!=s[j].b[k]) {
						pd2=false;
					}
				}
				if(pd2==true) {
//					printf("the first string in this a and the second one is same.\n");
					continue;
				}
				bool pd = true;
				for(int k=0; k<l; k++) {
					if(t[i].a[k] !=t[i].b[k]) {
						pd=false;
					}
				}
				for(int k=r+1; k<t[i].a.size(); k++) {
					if(t[i].a[k] !=t[i].b[k]) {
						pd=false;
					}
				}
				if(pd==false) {
//					printf("The chars in front of Left or behind Right is not same.\n");
					continue;
				}
				for(int k=l,m=0; k<=r; k++,m++) {
					if(t[i].a[k]!=s[j].a[m]) {
						pd=false;
					}
				}
				if(pd==false) {
//					printf("Unable to use this s translate t.\n");
					continue;
				}
				for(int k=l,m=0; k<=r; k++,m++) {
					if(t[i].b[k]!=s[j].b[m]) {
						pd=false;
					}
				}
				if(pd==false) {
					continue;
				} else {
//					printf("Success! Answer change into %d\n",ans+1);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
//	cout<<endl;
	return 0;
}
