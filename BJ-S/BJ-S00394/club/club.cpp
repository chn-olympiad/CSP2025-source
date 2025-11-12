#include<iostream>
#include<algorithm>
using namespace std;
struct work{
    long long x,y,z,id;
    long long cha,maxx;
}a[1000005];
long long top[1000005];
long long sum;
bool cmp(work a,work b){
    if(a.cha != b.cha)return a.cha < b.cha;
    else return a.id < b.id;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin >> t;
    for(int tt = 0;tt < t;tt++){
    long long n;
    cin >> n;
    for(int i = 0;i < n;i++){
        a[i].id = i;
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].maxx = max(a[i].x,max(a[i].y,a[i].z));
        if(a[i].maxx == a[i].x){
            top[1]++;
            a[i].cha = min(a[i].maxx-a[i].y,a[i].maxx-a[i].z);
        }else if(a[i].maxx == a[i].y){
            top[2]++;
            a[i].cha = min(a[i].maxx-a[i].x,a[i].maxx-a[i].z);
        }else if(a[i].maxx == a[i].z){
            top[3]++;
            a[i].cha = min(a[i].maxx-a[i].y,a[i].maxx-a[i].x);
        }
    }
    if(top[1] <= n/2 && top[2] <= n/2 && top[3] <= n/2){
        for(int i = 0;i < n;i++)sum += a[i].maxx;
    }
    sort(a,a+n,cmp);
    if(top[1] > n/2){
        long long me = top[1]-n/2;
        for(int i = 0;i < n;i++){
            if(a[i].maxx == a[i].x && me != 0){
                me--;
                sum += a[i].maxx-a[i].cha;
            }else{
                sum += a[i].maxx;
            }
        }
    }
    if(top[2] > n/2){
        long long me = top[2]-n/2;
        for(int i = 0;i < n;i++){
            if(a[i].maxx == a[i].y && me != 0){
                me--;
                sum += a[i].maxx-a[i].cha;
            }else{
                sum += a[i].maxx;
            }
        }
    }
    if(top[3] > n/2){
        long long me = top[3]-n/2;
        for(int i = 0;i < n;i++){
            if(a[i].maxx == a[i].z && me != 0){
                me--;
                sum += a[i].maxx-a[i].cha;
            }else{
                sum += a[i].maxx;
            }
        }
    }
    cout << sum << endl;
    top[1] = 0;
    top[2] = 0;
    top[3] = 0;
    sum = 0;
    }
    return 0;
}
