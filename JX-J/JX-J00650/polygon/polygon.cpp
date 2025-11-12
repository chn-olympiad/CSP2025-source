#include <bits/stdc++.h>
using namespace std;
const int N=510;
int n;
int a[N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    if (n==1 || n==2) {
        cout<<0;
    } else {
        int cnt=0;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    int mx=max(a[i], max(a[j], a[k]));
                    if (mx*2<a[i]+a[j]+a[k]) {
                        cnt++;
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        int mx=max(a[i], max(a[j], max(a[k], a[g])));
                        if (mx*2<a[i]+a[j]+a[k]+a[g]) {
                            cnt++;
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            int mx=max(a[i], max(a[j], max(a[k], max(a[g], a[h]))));
                            if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]) {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                               int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], a[x])))));
                                if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]) {
                                    cnt++;
                                }
                            }
                        }

                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], a[d]))))));
                                    if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]) {
                                        cnt++;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], a[y])))))));
                                        if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]) {
                                            cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], a[w]))))))));
                                            if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]) {
                                                cnt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], a[e])))))))));
                                                if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]) {
                                                    cnt++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], a[u]))))))))));
                                                    if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]) {
                                                        cnt++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], a[f])))))))))));
                                                        if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]) {
                                                            cnt++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], a[q]))))))))))));
                                                            if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]) {
                                                                cnt++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], a[p])))))))))))));
                                                                if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]) {
                                                                    cnt++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                for (int c=p+1; c<=n; c++) {
                                                                    int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], max(a[p], a[c]))))))))))))));
                                                                    if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]+a[c]) {
                                                                        cnt++;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                for (int c=p+1; c<=n; c++) {
                                                                    for (int s=c+1; s<=n; s++) {
                                                                        int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], max(a[p], max(a[c], a[s])))))))))))))));
                                                                        if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]+a[c]+a[s]) {
                                                                            cnt++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                for (int c=p+1; c<=n; c++) {
                                                                    for (int s=c+1; s<=n; s++) {
                                                                        for (int v=s+1; v<=n; v++) {
                                                                            int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], max(a[p], max(a[c], max(a[s], a[v]))))))))))))))));
                                                                            if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]+a[c]+a[s]+a[v]) {
                                                                                cnt++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                for (int c=p+1; c<=n; c++) {
                                                                    for (int s=c+1; s<=n; s++) {
                                                                        for (int v=s+1; v<=n; v++) {
                                                                            for (int t=v+1; t<=n; t++) {
                                                                                int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], max(a[p], max(a[c], max(a[s], max(a[v], a[t])))))))))))))))));
                                                                                if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]+a[c]+a[s]+a[v]+a[t]) {
                                                                                    cnt++;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                for (int c=p+1; c<=n; c++) {
                                                                    for (int s=c+1; s<=n; s++) {
                                                                        for (int v=s+1; v<=n; v++) {
                                                                            for (int t=v+1; t<=n; t++) {
                                                                                for (int r=t+1; r<=n; r++) {
                                                                                    int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], max(a[p], max(a[c], max(a[s], max(a[v], a[r])))))))))))))))));
                                                                                    if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]+a[c]+a[s]+a[v]+a[t]+a[r]) {
                                                                                        cnt++;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    for (int g=k+1; g<=n; g++) {
                        for (int h=g+1; h<=n; h++) {
                            for (int x=h+1; x<=n; x++) {
                                for (int d=x+1; d<=n; d++) {
                                    for (int y=d+1; y<=n; y++) {
                                        for (int w=y+1; w<=n; w++) {
                                            for (int e=w+1; e<=n; e++) {
                                                for (int u=e+1; u<=n; u++) {
                                                    for (int f=u+1; f<=n; f++) {
                                                        for (int q=f+1; q<=n; q++) {
                                                            for (int p=q+1; p<=n; p++) {
                                                                for (int c=p+1; c<=n; c++) {
                                                                    for (int s=c+1; s<=n; s++) {
                                                                        for (int v=s+1; v<=n; v++) {
                                                                            for (int t=v+1; t<=n; t++) {
                                                                                for (int r=t+1; r<=n; r++) {
                                                                                    for (int m=r+1; m<=n; m++) {
                                                                                        int mx=max(a[i], max(a[j], max(a[k], max(a[g], max(a[h], max(a[x], max(a[d], max(a[y], max(a[w], max(a[e], max([u], max(a[f], max(a[q], max(a[p], max(a[c], max(a[s], max(a[v], max(a[r], a[m]))))))))))))))))));
                                                                                        if (mx*2<a[i]+a[j]+a[k]+a[g]+a[h]+a[x]+a[d]+a[y]+a[w]+a[e]+a[u]+a[f]+a[q]+a[p]+a[c]+a[s]+a[v]+a[t]+a[r]+a[m]) {
                                                                                            cnt++;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
