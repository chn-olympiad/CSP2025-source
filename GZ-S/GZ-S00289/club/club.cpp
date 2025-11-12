//GZ-S00289 华东师范大学附属贵阳学校 段永琦
#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n),c(n);
        for(int i=0;i<n;++i)cin>>a[i]>>b[i]>>c[i];
        int cnt1=0,cnt2=0,cnt3=0;
        int res=0;
        for(int i=0;i<n;++i){
            int max_val=max({a[i],b[i],c[i]});
            if(max_val==a[i]&&cnt1<n/2){
                res+=a[i];
                cnt1++;
            } else if (max_val == b[i] && cnt2 < n / 2) {
                res += b[i];
                cnt2++;
            } else if (max_val == c[i] && cnt3 < n / 2) {
                res += c[i];
                cnt3++;
            } else {
                int max1 = max({a[i], b[i], c[i]});
                int max2 = -1;
                if (a[i] != max1) max2 = max(max2, a[i]);
                if (b[i] != max1) max2 = max(max2, b[i]);
                if (c[i] != max1) max2 = max(max2, c[i]);
                if (max2 == a[i] && cnt1 < n / 2) {
                    res += a[i];
                    cnt1++;
                } else if (max2 == b[i] && cnt2 < n / 2) {
                    res += b[i];
                    cnt2++;
                } else if (max2 == c[i] && cnt3 < n / 2) {
                    res += c[i];
                    cnt3++;
                } else {
                    res += min({a[i], b[i], c[i]});
                    if (a[i] == min({a[i], b[i], c[i]}) && cnt1 < n / 2) {
                        cnt1++;
                    } else if (b[i] == min({a[i], b[i], c[i]}) && cnt2 < n / 2) {
                        cnt2++;
                    } else {
                        cnt3++;
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

