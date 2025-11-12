#include <bits/stdc++.h>
using namespace std;
int n,t;


bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int j=0;j<t;j++){
        int stud[100001][4];
        int c1=0;int c2=0;int c3=0;
        cin >> n;
        vector<pair<int,int> > highest(n);
        for(int i=0;i<n;i++){
            cin >> stud[i][0];
            cin >> stud[i][1];
            cin >> stud[i][2];
            stud[i][3] = 0;
            highest[i] = make_pair(max(stud[i][0],max(stud[i][1],stud[i][2])),i);
        }
        int cnt=0;
        sort(highest.begin(),highest.end(),cmp);
        for(int i=0;i<highest.size();i++){
            int pos = highest[i].second;
            if(stud[pos][0]==highest[i].first){
                stud[pos][0]=-1;
                if(c1<n/2){
                    stud[pos][3] = -1;
                    c1++;
                    cnt+=highest[i].first;
                }
            }else if(stud[pos][1]==highest[i].first){
                stud[pos][1]=-1;
                if(c2<n/2){
                    stud[pos][3] = -1;
                    c2++;
                    cnt+=highest[i].first;
                }
            }else{
                stud[pos][2]=-1;
                if(c3<n/2){
                    stud[pos][3] = -1;
                    c3++;
                    cnt+=highest[i].first;
                }
            }
        }
        vector<pair<int,int> > highest2;
        for(int i=0;i<n;i++){
            if(stud[i][3]==0){
                highest2.push_back(make_pair(max(stud[i][0],max(stud[i][1],stud[i][2])),i));
            }
        }
        sort(highest2.begin(),highest2.end(),cmp);
        for(int i=0;i<highest2.size();i++){
            int pos = highest2[i].second;
            if(stud[pos][0]==highest2[i].first){
                stud[pos][0]=-1;
                if(c1<n/2){
                    stud[pos][3] = -1;
                    c1++;
                    cnt+=highest2[i].first;
                }
            }else if(stud[pos][1]==highest2[i].first){
                stud[pos][1]=-1;
                if(c2<n/2){
                    stud[pos][3] = -1;
                    c2++;
                    cnt+=highest2[i].first;
                }
            }else{
                stud[pos][2]=-1;
                if(c3<n/2){
                    stud[pos][3] = -1;
                    c3++;
                    cnt+=highest2[i].first;
                }
            }
        }
        vector<pair<int,int> > highest3;
        for(int i=0;i<n;i++){
            if(stud[i][3]==0){
                highest3.push_back(make_pair(max(stud[i][0],max(stud[i][1],stud[i][2])),i));
            }
        }
        sort(highest3.begin(),highest3.end(),cmp);
        for(int i=0;i<highest3.size();i++){
            int pos = highest3[i].second;
            if(stud[pos][0]==highest3[i].first){
                stud[pos][0]=-1;
                if(c1<n/2){
                    stud[pos][3] = -1;
                    c1++;
                    cnt+=highest3[i].first;
                }
            }else if(stud[pos][1]==highest3[i].first){
                stud[pos][1]=-1;
                if(c2<n/2){
                    stud[pos][3] = -1;
                    c2++;
                    cnt+=highest3[i].first;
                }
            }else{
                stud[pos][2]=-1;
                if(c3<n/2){
                    stud[pos][3] = -1;
                    c3++;
                    cnt+=highest3[i].first;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
