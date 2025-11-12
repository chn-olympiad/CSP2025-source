#include<bits/stdc++.h>
using namespace std;
bool f;
int a[1000091],b[917813],k=1,ans,q[100009];
int s[109][109];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==1){
        cout<<0;
    }else{
        if(n==2){
            cout<<0;

        }else{
            if(n==3){
                for(int i=1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        for(int k=j+1;k<=n;k++){
                            if((a[i]+a[j]+a[k])>a[k]*2){
                                ans++;
                            }

                        }

                    }
                }

            }else{
                if(n==4){
                    for(int i=1;i<=n;i++){
                        for(int j=i+1;j<=n;j++){
                            for(int k=j+1;k<=n;k++){
                                if((a[i]+a[j]+a[k])>a[k]*2){
                                    ans++;
                                }

                            }

                        }
                    }
                    for(int i=1;i<=n;i++){
                        for(int j=i+1;j<=n;j++){
                            for(int k=j+1;k<=n;k++){
                                for(int q=k+1;q<=n;q++){
                                    if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                        ans++;
                                    }
                                }


                            }

                        }
                    }
                }else{
                    if(n==5){
                        for(int i=1;i<=n;i++){
                            for(int j=i+1;j<=n;j++){
                                for(int k=j+1;k<=n;k++){
                                    if((a[i]+a[j]+a[k])>a[k]*2){
                                        ans++;
                                    }

                                }

                            }
                        }
                        for(int i=1;i<=n;i++){
                            for(int j=i+1;j<=n;j++){
                                for(int k=j+1;k<=n;k++){
                                    for(int q=k+1;q<=n;q++){
                                        if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                            ans++;
                                        }
                                    }


                                }

                            }
                        }
                        for(int i=1;i<=n;i++){
                            for(int j=i+1;j<=n;j++){
                                for(int k=j+1;k<=n;k++){
                                    for(int q=k+1;q<=n;q++){
                                        for(int w=q+1;w<=n;w++){
                                            if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                ans++;
                                            }

                                        }
                                    }


                                }

                            }
                        }

                    }else{
                        if(n==6){
                            for(int i=1;i<=n;i++){
                                for(int j=i+1;j<=n;j++){
                                    for(int k=j+1;k<=n;k++){
                                        if((a[i]+a[j]+a[k])>a[k]*2){
                                            ans++;
                                        }

                                    }

                                }
                            }
                            for(int i=1;i<=n;i++){
                                for(int j=i+1;j<=n;j++){
                                    for(int k=j+1;k<=n;k++){
                                        for(int q=k+1;q<=n;q++){
                                            if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                ans++;
                                            }
                                        }


                                    }

                                }
                            }
                            for(int i=1;i<=n;i++){
                                for(int j=i+1;j<=n;j++){
                                    for(int k=j+1;k<=n;k++){
                                        for(int q=k+1;q<=n;q++){
                                            for(int w=q+1;w<=n;w++){
                                                if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                    ans++;
                                                }

                                            }
                                        }


                                    }

                                }
                            }
                            for(int i=1;i<=n;i++){
                                for(int j=i+1;j<=n;j++){
                                    for(int k=j+1;k<=n;k++){
                                        for(int q=k+1;q<=n;q++){
                                            for(int w=q+1;w<=n;w++){
                                                for(int e=w+1;e<=n;e++){
                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                        ans++;
                                                    }
                                                }


                                            }
                                        }


                                    }

                                }
                            }
                        }else{
                            if(n==7){
                                for(int i=1;i<=n;i++){
                                    for(int j=i+1;j<=n;j++){
                                        for(int k=j+1;k<=n;k++){
                                            if((a[i]+a[j]+a[k])>a[k]*2){
                                                ans++;
                                            }

                                        }

                                    }
                                }
                                for(int i=1;i<=n;i++){
                                    for(int j=i+1;j<=n;j++){
                                        for(int k=j+1;k<=n;k++){
                                            for(int q=k+1;q<=n;q++){
                                                if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                    ans++;
                                                }
                                            }


                                        }

                                    }
                                }
                                for(int i=1;i<=n;i++){
                                    for(int j=i+1;j<=n;j++){
                                        for(int k=j+1;k<=n;k++){
                                            for(int q=k+1;q<=n;q++){
                                                for(int w=q+1;w<=n;w++){
                                                    if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                        ans++;
                                                    }

                                                }
                                            }


                                        }

                                    }
                                }
                                for(int i=1;i<=n;i++){
                                    for(int j=i+1;j<=n;j++){
                                        for(int k=j+1;k<=n;k++){
                                            for(int q=k+1;q<=n;q++){
                                                for(int w=q+1;w<=n;w++){
                                                    for(int e=w+1;e<=n;e++){
                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                            ans++;
                                                        }
                                                    }


                                                }
                                            }


                                        }

                                    }
                                }
                                for(int i=1;i<=n;i++){
                                    for(int j=i+1;j<=n;j++){
                                        for(int k=j+1;k<=n;k++){
                                            for(int q=k+1;q<=n;q++){
                                                for(int w=q+1;w<=n;w++){
                                                    for(int e=w+1;e<=n;e++){
                                                        for(int r=e+1;r<=n;r++){
                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }


                                                }
                                            }


                                        }

                                    }
                                }
                            }else{
                                if(n==8){
                                    for(int i=1;i<=n;i++){
                                        for(int j=i+1;j<=n;j++){
                                            for(int k=j+1;k<=n;k++){
                                                if((a[i]+a[j]+a[k])>a[k]*2){
                                                    ans++;
                                                }

                                            }

                                        }
                                    }
                                    for(int i=1;i<=n;i++){
                                        for(int j=i+1;j<=n;j++){
                                            for(int k=j+1;k<=n;k++){
                                                for(int q=k+1;q<=n;q++){
                                                    if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                        ans++;
                                                    }
                                                }


                                            }

                                        }
                                    }
                                    for(int i=1;i<=n;i++){
                                        for(int j=i+1;j<=n;j++){
                                            for(int k=j+1;k<=n;k++){
                                                for(int q=k+1;q<=n;q++){
                                                    for(int w=q+1;w<=n;w++){
                                                        if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                            ans++;
                                                        }

                                                    }
                                                }


                                            }

                                        }
                                    }
                                    for(int i=1;i<=n;i++){
                                        for(int j=i+1;j<=n;j++){
                                            for(int k=j+1;k<=n;k++){
                                                for(int q=k+1;q<=n;q++){
                                                    for(int w=q+1;w<=n;w++){
                                                        for(int e=w+1;e<=n;e++){
                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                                ans++;
                                                            }
                                                        }


                                                    }
                                                }


                                            }

                                        }
                                    }
                                    for(int i=1;i<=n;i++){
                                        for(int j=i+1;j<=n;j++){
                                            for(int k=j+1;k<=n;k++){
                                                for(int q=k+1;q<=n;q++){
                                                    for(int w=q+1;w<=n;w++){
                                                        for(int e=w+1;e<=n;e++){
                                                            for(int r=e+1;r<=n;r++){
                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }


                                                    }
                                                }


                                            }

                                        }
                                    }
                                    for(int i=1;i<=n;i++){
                                        for(int j=i+1;j<=n;j++){
                                            for(int k=j+1;k<=n;k++){
                                                for(int q=k+1;q<=n;q++){
                                                    for(int w=q+1;w<=n;w++){
                                                        for(int e=w+1;e<=n;e++){
                                                            for(int r=e+1;r<=n;r++){
                                                                for(int t=r+1;t<=n;t++){
                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>a[t]*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }


                                                    }
                                                }


                                            }

                                        }
                                    }
                                }else{
                                    if(n==9){
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    if((a[i]+a[j]+a[k])>a[k]*2){
                                                        ans++;
                                                    }

                                                }

                                            }
                                        }
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int q=k+1;q<=n;q++){
                                                        if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                            ans++;
                                                        }
                                                    }


                                                }

                                            }
                                        }
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int q=k+1;q<=n;q++){
                                                        for(int w=q+1;w<=n;w++){
                                                            if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                                ans++;
                                                            }

                                                        }
                                                    }


                                                }

                                            }
                                        }
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int q=k+1;q<=n;q++){
                                                        for(int w=q+1;w<=n;w++){
                                                            for(int e=w+1;e<=n;e++){
                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                                    ans++;
                                                                }
                                                            }


                                                        }
                                                    }


                                                }

                                            }
                                        }
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int q=k+1;q<=n;q++){
                                                        for(int w=q+1;w<=n;w++){
                                                            for(int e=w+1;e<=n;e++){
                                                                for(int r=e+1;r<=n;r++){
                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                        ans++;
                                                                    }
                                                                }
                                                            }


                                                        }
                                                    }


                                                }

                                            }
                                        }
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int q=k+1;q<=n;q++){
                                                        for(int w=q+1;w<=n;w++){
                                                            for(int e=w+1;e<=n;e++){
                                                                for(int r=e+1;r<=n;r++){
                                                                    for(int t=r+1;t<=n;t++){
                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>a[t]*2){
                                                                            ans++;
                                                                        }
                                                                    }

                                                                }
                                                            }


                                                        }
                                                    }


                                                }

                                            }
                                        }
                                        for(int i=1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int q=k+1;q<=n;q++){
                                                        for(int w=q+1;w<=n;w++){
                                                            for(int e=w+1;e<=n;e++){
                                                                for(int r=e+1;r<=n;r++){
                                                                    for(int t=r+1;t<=n;t++){
                                                                        for(int y=t+1;y<=n;y++){
                                                                             if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y])>a[y]*2){
                                                                                ans++;
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

                                    }else{
                                        if(n==10){
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        if((a[i]+a[j]+a[k])>a[k]*2){
                                                            ans++;
                                                        }

                                                    }

                                                }
                                            }
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                                ans++;
                                                            }
                                                        }


                                                    }

                                                }
                                            }
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            for(int w=q+1;w<=n;w++){
                                                                if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                                    ans++;
                                                                }

                                                            }
                                                        }


                                                    }

                                                }
                                            }
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            for(int w=q+1;w<=n;w++){
                                                                for(int e=w+1;e<=n;e++){
                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                                        ans++;
                                                                    }
                                                                }


                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            for(int w=q+1;w<=n;w++){
                                                                for(int e=w+1;e<=n;e++){
                                                                    for(int r=e+1;r<=n;r++){
                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                            ans++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            for(int w=q+1;w<=n;w++){
                                                                for(int e=w+1;e<=n;e++){
                                                                    for(int r=e+1;r<=n;r++){
                                                                        for(int t=r+1;t<=n;t++){
                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>a[t]*2){
                                                                                ans++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                }
                                            }
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            for(int w=q+1;w<=n;w++){
                                                                for(int e=w+1;e<=n;e++){
                                                                    for(int r=e+1;r<=n;r++){
                                                                        for(int t=r+1;t<=n;t++){
                                                                            for(int y=t+1;y<=n;y++){
                                                                                 if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y])>a[y]*2){
                                                                                    ans++;
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
                                            for(int i=1;i<=n;i++){
                                                for(int j=i+1;j<=n;j++){
                                                    for(int k=j+1;k<=n;k++){
                                                        for(int q=k+1;q<=n;q++){
                                                            for(int w=q+1;w<=n;w++){
                                                                for(int e=w+1;e<=n;e++){
                                                                    for(int r=e+1;r<=n;r++){
                                                                        for(int t=r+1;t<=n;t++){
                                                                            for(int y=t+1;y<=n;y++){
                                                                                for(int u=y+1;u<=n;u++){
                                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u])>a[u]*2){
                                                                                        ans++;
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
                                        }else{
                                            if(n==11){
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            if((a[i]+a[j]+a[k])>a[k]*2){
                                                                ans++;
                                                            }

                                                        }

                                                    }
                                                }
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                                    ans++;
                                                                }
                                                            }


                                                        }

                                                    }
                                                }
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                                        ans++;
                                                                    }

                                                                }
                                                            }


                                                        }

                                                    }
                                                }
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    for(int e=w+1;e<=n;e++){
                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                                            ans++;
                                                                        }
                                                                    }


                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    for(int e=w+1;e<=n;e++){
                                                                        for(int r=e+1;r<=n;r++){
                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                                ans++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    for(int e=w+1;e<=n;e++){
                                                                        for(int r=e+1;r<=n;r++){
                                                                            for(int t=r+1;t<=n;t++){
                                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>a[t]*2){
                                                                                    ans++;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                    }
                                                }
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    for(int e=w+1;e<=n;e++){
                                                                        for(int r=e+1;r<=n;r++){
                                                                            for(int t=r+1;t<=n;t++){
                                                                                for(int y=t+1;y<=n;y++){
                                                                                     if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y])>a[y]*2){
                                                                                        ans++;
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
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    for(int e=w+1;e<=n;e++){
                                                                        for(int r=e+1;r<=n;r++){
                                                                            for(int t=r+1;t<=n;t++){
                                                                                for(int y=t+1;y<=n;y++){
                                                                                    for(int u=y+1;u<=n;u++){
                                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u])>a[u]*2){
                                                                                            ans++;
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
                                                for(int i=1;i<=n;i++){
                                                    for(int j=i+1;j<=n;j++){
                                                        for(int k=j+1;k<=n;k++){
                                                            for(int q=k+1;q<=n;q++){
                                                                for(int w=q+1;w<=n;w++){
                                                                    for(int e=w+1;e<=n;e++){
                                                                        for(int r=e+1;r<=n;r++){
                                                                            for(int t=r+1;t<=n;t++){
                                                                                for(int y=t+1;y<=n;y++){
                                                                                    for(int u=y+1;u<=n;u++){
                                                                                        for(int o=u+1;o<=n;o++){
                                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o])>a[o]*2){
                                                                                                ans++;
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
                                            }else{
                                                if(n==12){
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                if((a[i]+a[j]+a[k])>a[k]*2){
                                                                    ans++;
                                                                }

                                                            }

                                                        }
                                                    }
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                                        ans++;
                                                                    }
                                                                }


                                                            }

                                                        }
                                                    }
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                                            ans++;
                                                                        }

                                                                    }
                                                                }


                                                            }

                                                        }
                                                    }
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                                                ans++;
                                                                            }
                                                                        }


                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            for(int r=e+1;r<=n;r++){
                                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                                    ans++;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            for(int r=e+1;r<=n;r++){
                                                                                for(int t=r+1;t<=n;t++){
                                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>a[t]*2){
                                                                                        ans++;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                        }
                                                    }
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            for(int r=e+1;r<=n;r++){
                                                                                for(int t=r+1;t<=n;t++){
                                                                                    for(int y=t+1;y<=n;y++){
                                                                                         if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y])>a[y]*2){
                                                                                            ans++;
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
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            for(int r=e+1;r<=n;r++){
                                                                                for(int t=r+1;t<=n;t++){
                                                                                    for(int y=t+1;y<=n;y++){
                                                                                        for(int u=y+1;u<=n;u++){
                                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u])>a[u]*2){
                                                                                                ans++;
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
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            for(int r=e+1;r<=n;r++){
                                                                                for(int t=r+1;t<=n;t++){
                                                                                    for(int y=t+1;y<=n;y++){
                                                                                        for(int u=y+1;u<=n;u++){
                                                                                            for(int o=u+1;o<=n;o++){
                                                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o])>a[o]*2){
                                                                                                    ans++;
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
                                                    for(int i=1;i<=n;i++){
                                                        for(int j=i+1;j<=n;j++){
                                                            for(int k=j+1;k<=n;k++){
                                                                for(int q=k+1;q<=n;q++){
                                                                    for(int w=q+1;w<=n;w++){
                                                                        for(int e=w+1;e<=n;e++){
                                                                            for(int r=e+1;r<=n;r++){
                                                                                for(int t=r+1;t<=n;t++){
                                                                                    for(int y=t+1;y<=n;y++){
                                                                                        for(int u=y+1;u<=n;u++){
                                                                                            for(int o=u+1;o<=n;o++){
                                                                                                for(int p=o+1;p<=n;p++){
                                                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p])>a[p]*2){
                                                                                                        ans++;
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
                                                }else{
                                                    if(n==13){
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    if((a[i]+a[j]+a[k])>a[k]*2){
                                                                        ans++;
                                                                    }

                                                                }

                                                            }
                                                        }
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        if((a[i]+a[j]+a[k]+a[q])>a[q]*2){
                                                                            ans++;
                                                                        }
                                                                    }


                                                                }

                                                            }
                                                        }
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w])>a[w]*2){
                                                                                ans++;
                                                                            }

                                                                        }
                                                                    }


                                                                }

                                                            }
                                                        }
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>a[e]*2){
                                                                                    ans++;
                                                                                }
                                                                            }


                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>a[r]*2){
                                                                                        ans++;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    for(int t=r+1;t<=n;t++){
                                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>a[t]*2){
                                                                                            ans++;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                            }
                                                        }
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    for(int t=r+1;t<=n;t++){
                                                                                        for(int y=t+1;y<=n;y++){
                                                                                             if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y])>a[y]*2){
                                                                                                ans++;
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
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    for(int t=r+1;t<=n;t++){
                                                                                        for(int y=t+1;y<=n;y++){
                                                                                            for(int u=y+1;u<=n;u++){
                                                                                                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u])>a[u]*2){
                                                                                                    ans++;
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
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    for(int t=r+1;t<=n;t++){
                                                                                        for(int y=t+1;y<=n;y++){
                                                                                            for(int u=y+1;u<=n;u++){
                                                                                                for(int o=u+1;o<=n;o++){
                                                                                                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o])>a[o]*2){
                                                                                                        ans++;
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
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    for(int t=r+1;t<=n;t++){
                                                                                        for(int y=t+1;y<=n;y++){
                                                                                            for(int u=y+1;u<=n;u++){
                                                                                                for(int o=u+1;o<=n;o++){
                                                                                                    for(int p=o+1;p<=n;p++){
                                                                                                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p])>a[p]*2){
                                                                                                            ans++;
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
                                                        for(int i=1;i<=n;i++){
                                                            for(int j=i+1;j<=n;j++){
                                                                for(int k=j+1;k<=n;k++){
                                                                    for(int q=k+1;q<=n;q++){
                                                                        for(int w=q+1;w<=n;w++){
                                                                            for(int e=w+1;e<=n;e++){
                                                                                for(int r=e+1;r<=n;r++){
                                                                                    for(int t=r+1;t<=n;t++){
                                                                                        for(int y=t+1;y<=n;y++){
                                                                                            for(int u=y+1;u<=n;u++){
                                                                                                for(int o=u+1;o<=n;o++){
                                                                                                    for(int p=o+1;p<=n;p++){
                                                                                                        for(int aa=p+1;aa<=n;aa++){
                                                                                                            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[aa])>a[aa]*2){
                                                                                                                ans++;
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
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
