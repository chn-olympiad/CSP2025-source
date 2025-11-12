#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5010],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1||n==2){
        cout<<"0";
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    if(n==4){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        if(i+j+k+o>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]>2*max(i*a[1],max(j*a[2],max(k*a[3],o*a[4])))){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
    if(n==5){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            if(i+j+k+o+x>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],x*a[5]))))){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
    if(n==6){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                if(i+j+k+o+x+y>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],y*a[6])))))){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
    if(n==7){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    if(i+j+k+o+x+y+z>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],z*a[7]))))))){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
    if(n==8){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        if(i+j+k+o+x+y+z+p>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],p*a[8])))))))){
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
        cout<<ans;
    }
    if(n==9){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            if(i+j+k+o+x+y+z+p+q>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],q*a[9]))))))))){
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
        cout<<ans;
    }
    if(n==10){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                if(i+j+k+o+x+y+z+p+q+w>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],w*a[10])))))))))){
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
        cout<<ans;
    }
    if(n==11){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    if(i+j+k+o+x+y+z+p+q+w+e>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],e*a[11]))))))))))){
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
        cout<<ans;
    }
    if(n==12){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        if(i+j+k+o+x+y+z+p+q+w+e+r>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],r*a[12])))))))))))){
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
        cout<<ans;
    }
    if(n==13){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            if(i+j+k+o+x+y+z+p+q+w+e+r+t>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],t*a[13]))))))))))))){
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
        cout<<ans;
    }
    if(n==14){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                if(i+j+k+o+x+y+z+p+q+w+e+r+t+u>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],u*a[14])))))))))))))){
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
        cout<<ans;
    }
    if(n==15){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                for(LL s=0;s<=1;s++){
                                                                    if(i+j+k+o+x+y+z+p+q+w+e+r+t+u+s>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]+s*a[15]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],max(u*a[14],s*a[15]))))))))))))))){
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
        cout<<ans;
    }
    if(n==16){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                for(LL s=0;s<=1;s++){
                                                                    for(LL d=0;d<=1;d++){
                                                                        if(i+j+k+o+x+y+z+p+q+w+e+r+t+u+s+d>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]+s*a[15]+d*a[16]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],max(u*a[14],max(s*a[15],d*a[16])))))))))))))))){
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
        cout<<ans;
    }
    if(n==17){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                for(LL s=0;s<=1;s++){
                                                                    for(LL d=0;d<=1;d++){
                                                                        for(LL f=0;f<=1;f++){
                                                                            if(i+j+k+o+x+y+z+p+q+w+e+r+t+u+s+d+f>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]+s*a[15]+d*a[16]+f*a[17]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],max(u*a[14],max(s*a[15],max(d*a[16],f*a[17]))))))))))))))))){
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
        cout<<ans;
    }
    if(n==18){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                for(LL s=0;s<=1;s++){
                                                                    for(LL d=0;d<=1;d++){
                                                                        for(LL f=0;f<=1;f++){
                                                                            for(LL g=0;g<=1;g++){
                                                                                if(i+j+k+o+x+y+z+p+q+w+e+r+t+u+s+d+f+g>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]+s*a[15]+d*a[16]+f*a[17]+g*a[18]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],max(u*a[14],max(s*a[15],max(d*a[16],max(f*a[17],g*a[18])))))))))))))))))){
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
        cout<<ans;
    }
    if(n==19){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                for(LL s=0;s<=1;s++){
                                                                    for(LL d=0;d<=1;d++){
                                                                        for(LL f=0;f<=1;f++){
                                                                            for(LL g=0;g<=1;g++){
                                                                                for(LL h=0;h<=1;h++){
                                                                                    if(i+j+k+o+x+y+z+p+q+w+e+r+t+u+s+d+f+g+h>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]+s*a[15]+d*a[16]+f*a[17]+g*a[18]+h*a[19]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],max(u*a[14],max(s*a[15],max(d*a[16],max(f*a[17],max(g*a[18],h*a[19]))))))))))))))))))){
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
        cout<<ans;
    }
    if(n==20){
        for(LL i=0;i<=1;i++){
            for(LL j=0;j<=1;j++){
                for(LL k=0;k<=1;k++){
                    for(LL o=0;o<=1;o++){
                        for(LL x=0;x<=1;x++){
                            for(LL y=0;y<=1;y++){
                                for(LL z=0;z<=1;z++){
                                    for(LL p=0;p<=1;p++){
                                        for(LL q=0;q<=1;q++){
                                            for(LL w=0;w<=1;w++){
                                                for(LL e=0;e<=1;e++){
                                                    for(LL r=0;r<=1;r++){
                                                        for(LL t=0;t<=1;t++){
                                                            for(LL u=0;u<=1;u++){
                                                                for(LL s=0;s<=1;s++){
                                                                    for(LL d=0;d<=1;d++){
                                                                        for(LL f=0;f<=1;f++){
                                                                            for(LL g=0;g<=1;g++){
                                                                                for(LL h=0;h<=1;h++){
                                                                                    for(LL l=0;l<=1;l++){
                                                                                        if(i+j+k+o+x+y+z+p+q+w+e+r+t+u+s+d+f+g+h+l>=3&&i*a[1]+j*a[2]+k*a[3]+o*a[4]+x*a[5]+y*a[6]+z*a[7]+p*a[8]+q*a[9]+w*a[10]+e*a[11]+r*a[12]+t*a[13]+u*a[14]+s*a[15]+d*a[16]+f*a[17]+g*a[18]+h*a[19]+l*a[20]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(o*a[4],max(x*a[5],max(y*a[6],max(z*a[7],max(p*a[8],max(q*a[9],max(w*a[10],max(e*a[11],max(r*a[12],max(t*a[13],max(u*a[14],max(s*a[15],max(d*a[16],max(f*a[17],max(g*a[18],max(h*a[19],l*a[20])))))))))))))))))))){
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
        cout<<ans;
    }
    return 0;
}
