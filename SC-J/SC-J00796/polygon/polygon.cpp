#include <bits/stdc++.h>
using namespace std;
const int M = 1e3+10;
int a[M];
int n,cnt;
void three()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) cnt++;
}
void four()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) cnt++;
}
void five()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) for(int m = l+1;m<=n;m++) if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))) cnt++;
}
void six()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) for(int m = l+1;m<=n;m++) for(int o = m+1;o<=n;o++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o])))))) cnt++;
}
void seven()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) for(int m = l+1;m<=n;m++) for(int o = m+1;o<=n;o++) for(int p = o+1;p<=n;p++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[p]))))))) cnt++;
}
void eight()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) for(int m = l+1;m<=n;m++) for(int o = m+1;o<=n;o++) for(int p = o+1;p<=n;p++) for(int q = p+1;q<=n;q++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[p],a[q])))))))) cnt++;
}
void nine()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) for(int m = l+1;m<=n;m++) for(int o = m+1;o<=n;o++) for(int p = o+1;p<=n;p++) for(int q = p+1;q<=n;q++) for(int r = q+1;r<=n;r++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],a[r]))))))))) cnt++;
}
void ten()
{
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) for(int k = j+1;k<=n;k++) for(int l = k+1;l<=n;l++) for(int m = l+1;m<=n;m++) for(int o = m+1;o<=n;o++) for(int p = o+1;p<=n;p++) for(int q = p+1;q<=n;q++) for(int r = q+1;r<=n;r++) for(int s = r+1;s<=n;s++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],max(a[r],a[s])))))))))) cnt++;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	if(n>=3) three();
	if(n>=4) four();
	if(n>=5) five();
	if(n>=6) six();
	if(n>=7) seven();
	if(n>=8) eight();
	if(n>=9) nine();
	if(n>=10) ten();
	cout<<cnt;
	return 0;
}