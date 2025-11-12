#include <bits/stdc++.h>
using namespace std;
int t,n;
int ans,ans1,ans2;
struct Save{
	int a;int b;int c;int wc;
}a[100004];
bool cmp(Save A,Save B){
	if (A.a==B.a)
		if (A.b==B.b) return A.c<B.c;
		else return A.b<B.b;
	else return A.a<B.a;}
bool cmp1(Save A,Save B){
	if (A.a==B.a)
		if (A.b==B.b) return A.c>B.c;
		else return A.b>B.b;
	else return A.a>B.a;}
bool cmp2(Save A,Save B){
	if (A.a==B.a)
		if (A.c==B.c) return A.b<B.b;
		else return A.c<B.c;
	else return A.a<B.a;}
bool cmp3(Save A,Save B){
	if (A.a==B.a)
		if (A.c==B.c) return A.b>B.b;
		else return A.c>B.c;
	else return A.a>B.a;}
bool cmp4(Save A,Save B){
	if (A.b==B.b)
		if (A.a==B.a) return A.c<B.c;
		else return A.a<B.a;
	else return A.b<B.b;}
bool cmp5(Save A,Save B){
	if (A.b==B.b)
		if (A.a==B.a) return A.c>B.c;
		else return A.a>B.a;
	else return A.b>B.b;}
bool cmp6(Save A,Save B){
	if (A.c==B.c)
		if (A.a==B.a) return A.b<B.b;
		else return A.a<B.a;
	else return A.c<B.c;}
bool cmp7(Save A,Save B){
	if (A.c==B.c)
		if (A.a==B.a) return A.b>B.b;
		else return A.a>B.a;
	else return A.c>B.c;}
bool cmp8(Save A,Save B){
	if (A.c==B.c)
		if (A.b==B.b) return A.a<B.a;
		else return A.b<B.b;
	else return A.c<B.c;}
bool cmp9(Save A,Save B){
	if (A.c==B.c)
		if (A.b==B.b) return A.a>B.a;
		else return A.b>B.b;
	else return A.c>B.c;}
bool cmp10(Save A,Save B){
	if (A.b==B.b)
		if (A.c==B.c) return A.a<B.a;
		else return A.c<B.c;
	else return A.b<B.b;}
bool cmp11(Save A,Save B){
	if (A.b==B.b)
		if (A.c==B.c) return A.a>B.a;
		else return A.c>B.c;
	else return A.b>B.b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;}
			ans2=0;
		for (int k=1;k<=6;k++){
			ans=ans1=0;
			a[0].a=0,a[0].b=0,a[0].c=0;
			if (k==1)sort (a+1,a+n+1,cmp);
			else if (k==2)sort (a+1,a+n+1,cmp2);
			else if (k==3)sort (a+1,a+n+1,cmp4);
			else if (k==4)sort (a+1,a+n+1,cmp6);
			else if (k==5)sort (a+1,a+n+1,cmp8);
			else if (k==6)sort (a+1,a+n+1,cmp10);
			for (int i=1;i<=n;i++){
				if (max(max(a[i].a,a[i].b),a[i].c)==a[i].a){
					if (a[0].a<n/2){
						a[i].wc=1;a[0].a++;
						continue;}
					else if (max(a[i].b,a[i].c)==a[i].b && a[0].b<n/2){
						a[i].wc=2;a[0].b++;continue;}
					else if (a[0].c<n/2) {
						a[i].wc=3;a[0].c++;continue;}
					else {
						a[i].wc=2;a[0].b++;continue;}}
				else if (max(max(a[i].a,a[i].b),a[i].c)==a[i].b){
					if (a[0].b<n/2){
						a[i].wc=2;a[0].b++;
						continue;}
					else if (max(a[i].a,a[i].c)==a[i].a && a[0].a<n/2){
						a[i].wc=1;a[0].a++;continue;}
					else if (a[0].c<n/2) {
						a[i].wc=3;a[0].c++;continue;}
					else {
						a[i].wc=1;a[0].a++;continue;}}
				else {
					if (a[0].c<n/2){
						a[i].wc=3;a[0].c++;
						continue;}
				else if (max(a[i].a,a[i].b)==a[i].a && a[0].a<n/2){
					a[i].wc=1;a[0].a++;continue;
				}
				else if (a[0].b<n/2) {
					a[i].wc=2;a[0].b++;continue;
				}
				else {
					a[i].wc=1;a[0].a++;continue;
				}
			}}
		for (int i=1;i<=n;i++){
			if (a[i].wc==1) ans+=a[i].a;
			else if (a[i].wc ==2) ans+=a[i].b;
			else ans+=a[i].c;
		}
		ans1=0;
		a[0].a=0,a[0].b=0,a[0].c=0;
		if (k==1)sort (a+1,a+n+1,cmp1);
		else if (k==2)sort (a+1,a+n+1,cmp3);
		else if (k==3)sort (a+1,a+n+1,cmp5);
		else if (k==4)sort (a+1,a+n+1,cmp7);
		else if (k==5)sort (a+1,a+n+1,cmp9);
		else if (k==6)sort (a+1,a+n+1,cmp11);
		for (int i=1;i<=n;i++){
			if (max(max(a[i].a,a[i].b),a[i].c)==a[i].a){
				if (a[0].a<n/2){
					a[i].wc=1;a[0].a++;
					continue;}
				else if (max(a[i].b,a[i].c)==a[i].b && a[0].b<n/2){
					a[i].wc=2;a[0].b++;continue;
				}
				else if (a[0].c<n/2) {
					a[i].wc=3;a[0].c++;continue;
				}
				else {
					a[i].wc=2;a[0].b++;continue;
				}
			}
			else if (max(max(a[i].a,a[i].b),a[i].c)==a[i].b){
				if (a[0].b<n/2){
					a[i].wc=2;a[0].b++;
					continue;
				}
				else if (max(a[i].a,a[i].c)==a[i].a && a[0].a<n/2){
					a[i].wc=1;a[0].a++;continue;
				}
				else if (a[0].c<n/2) {
					a[i].wc=3;a[0].c++;continue;
				}
				else {
					a[i].wc=1;a[0].a++;continue;
				}
			}
			else {
				if (a[0].c<n/2){
					a[i].wc=3;a[0].c++;
					continue;
				}
				else if (max(a[i].a,a[i].b)==a[i].a && a[0].a<n/2){
					a[i].wc=1;a[0].a++;continue;
				}
				else if (a[0].b<n/2) {
					a[i].wc=2;a[0].b++;continue;
				}
				else {
					a[i].wc=1;a[0].a++;continue;
				}
			}}
	for (int i=1;i<=n;i++){
			if (a[i].wc==1) ans1+=a[i].a;
			else if (a[i].wc ==2) ans1+=a[i].b;
			else ans1+=a[i].c;}
		ans2=max(ans2,max(ans1,ans));}
		cout << ans2;}
	return 0;
}
