#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5001],c,f=1;
long long C(int n,int p){
	if(p>n/2) p=n-p;
	long long num1=1,num2=1;
	for(int i=1;i<=p;i++){
		num1=num1*((n-i+1)%MOD)%MOD;
		num2=num2*((p-i+1)%MOD)%MOD;
	}
	return (num1/num2)%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f) for(int i=3;i<=n;i++) c=(c+C(n,i)%MOD)%MOD;
	else{
		for(int i=1;i<=n;++i){
for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k]) c++;}}}
	for(int i=1;i<=n;i++){for(int j=i+1;j<=n;j++){for(int k=j+1;k<=n;k++){
for(int o=k+1;o<=n;o++){if(max(a[i],max(a[j],max(a[k],a[o])))*2<a[i]+a[j]+a[k]+a[o]) c++;}}}}
	for(int i=1;i<=n;++i){for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){for(int o=k+1;o<=n;++o){
for(int s=o+1;s<=n;++s){
if(max(a[i],max(a[j],max(a[k],max(a[o],a[s]))))*2<a[i]+a[j]+a[k]+a[o]+a[s]) c++;}}}}}
	for(int i=1;i<=n;++i){for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){for(int o=k+1;o<=n;++o){for(int s=o+1;s<=n;++s){
for(int t=s+1;t<=n;++t){if(max(a[i],max(a[j],max(a[k],max(a[o],max(a[t],a[s])))))*2<a[i]+a[j]+a[k]+a[o]+a[s]+a[t]) c++;}}}}}}
	for(int i=1;i<=n;++i){for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){for(int o=k+1;o<=n;++o){for(int s=o+1;s<=n;++s){
for(int t=s+1;t<=n;++t){for(int r=t+1;r<=n;++r){
if(max(a[i],max(a[j],max(a[k],max(a[o],max(a[t],max(a[s],a[r]))))))*2<a[i]+a[j]+a[k]+a[o]+a[s]+a[t]+a[r]) c++;}}}}}}}
    for(int i=1;i<=n;++i){for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){for(int o=k+1;o<=n;++o){for(int s=o+1;s<=n;++s){
for(int t=s+1;t<=n;++t){for(int r=t+1;r<=n;++r){for(int e=r+1;e<=n;++e){if(max(a[i],max(a[j],max(a[k],max(a[o],max(a[t],max(a[s],max(a[r],a[e])))))))*2<a[i]+a[j]+a[k]+a[o]+a[s]+a[t]+a[r]+a[e]) c++;
}}}}}}}}for(int i=1;i<=n;++i){for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){for(int o=k+1;o<=n;++o){for(int s=o+1;s<=n;++s){
for(int t=s+1;t<=n;++t){for(int r=t+1;r<=n;++r){for(int e=r+1;e<=n;++e){for(int am=e+1;am<=n;++am){
if(max(a[i],max(a[j],max(a[k],max(a[o],max(a[t],max(a[s],max(a[r],max(a[e],a[am]))))))))*2<a[i]+a[j]+a[k]+a[o]+a[s]+a[t]+a[r]+a[e]+a[am]) c++;
}}}}}}}}}
for(int i=1;i<=n;++i){for(int j=i+1;j<=n;++j){for(int k=j+1;k<=n;++k){for(int o=k+1;o<=n;++o){for(int s=o+1;s<=n;++s){
for(int t=s+1;t<=n;++t){for(int r=t+1;r<=n;++r){for(int e=r+1;e<=n;++e){for(int am=e+1;am<=n;++am){for(int m=am+1;m<=n;am++){
if(max(a[i],max(a[j],max(a[k],max(a[o],max(a[t],max(a[s],max(a[r],max(a[e],max(a[m],a[am])))))))))*2<a[i]+a[j]+a[k]+a[o]+a[s]+a[t]+a[r]+a[e]+a[am]+a[m]) c++;
}}}}}}}}}}
	}
	cout<<c%MOD<<endl;
	return 0;
}
