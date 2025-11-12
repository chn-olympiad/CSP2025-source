#include<bits/stdc++.h>
using namespace std;

struct data{
	int a1,a2,a3;
	int l1,l2,l3;
}s[100086];

int n;
int h;

void init(){
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>s[i].a1>>s[i].a2>>s[i].a3;
	}
}

void doing(){
	int i;
	h=0;
	int b1=0,b2=0,b3=0;
	for(i=0;i<n;i++){
		s[i].l1=max((s[i].a1,s[i].a2),s[i].a3);
		s[i].l3=min((s[i].a1,s[i].a2),s[i].a3);
		if(s[i].a1!=s[i].l1 and s[i].a1!=s[i].l3){
			s[i].l2 = s[i].a1;
		}if(s[i].a2!=s[i].l1 and s[i].a2!=s[i].l3){
			s[i].l2 = s[i].a2;
		}if(s[i].a3!=s[i].l1 and s[i].a3!=s[i].l3){
			s[i].a3 = s[i].a1;
		}
		if(s[i].l1==s[i].a1){
			b1++;
			h+=s[i].a1;
		}if(s[i].l1==s[i].a2){
			b2++;
			h+=s[i].a2;
		}if(s[i].l1==s[i].a3){
			b3++;
			h+=s[i].a3;
		}
	}
	int mim=20025;
	while(b1<=n/2){
		for(i=0;i<n;i++){
			if(s[i].l1==s[i].a1){
				if(s[i].l1-s[i].l2 < mim){
					mim = s[i].l1-s[i].l2;
					s[i].l1=0;
					b1--;
					if(s[i].l2==s[i].a2){
						b2++;
					}else{
						b3++;
					}
					h=h-s[i].l1+s[i].l2;
				}
			}
		}
	}
	while(b2<=n/2){
		for(i=0;i<n;i++){
			if(s[i].l1==s[i].a2){
				if(s[i].l1-s[i].l2 < mim){
					mim = s[i].l1-s[i].l2;
					s[i].l1=0;
					b1--;
					if(s[i].l2==s[i].a1){
						b1++;
					}else{
						b3++;
					}
					h=h-s[i].l1+s[i].l2;
				}
			}
		}
	}
	while(b3<=n/2){
		for(i=0;i<n;i++){
			if(s[i].l1==s[i].a3){
				if(s[i].l1-s[i].l2 < mim){
					mim = s[i].l1-s[i].l2;
					s[i].l1=0;
					b1--;
					if(s[i].l2==s[i].a1){
						b1++;
					}else{
						b2++;
					}
					h=h-s[i].l1+s[i].l2;
				}
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int i;
	cin>>t;
	for(i=0;i<t;i++){
		init();
		doing();
		cout<<h;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
