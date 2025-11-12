#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> as,bs,cs;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int a[n][3];
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
                int siz=as.size();
                if(as.size()<n/2){
                    for(int j=0;j<as.size();j++){
                        if(a[i][0]>a[as[j]][0]){
                            as.insert(as.begin()+j,i);
                        }
                    }
                    if(as.size()==siz) as.push_back(i);
                }
                else{
                    if(a[i][0]>as[as.size()-1]){
                        as.erase(as.begin()+as.size()-1);
                        for(int j=0;j<as.size();j++){
                            if(a[i][0]>a[as[j]][0]){
                                as.insert(as.begin()+j,i);
                            }
                        }
                        if(as.size()!=siz) as.push_back(i);
                    }
                    else{
                        if(a[i][1]>a[i][2]){
                            if(bs.size()<n/2){
                                for(int j=0;j<bs.size();j++){
                                    if(a[i][0]>a[bs[j]][0]){
                                        bs.insert(bs.begin()+j,i);
                                    }
                                }
                                if(bs.size()==siz) bs.push_back(i);
                            }
                            else{
                                if(a[i][0]>bs[bs.size()-1]){
                                    bs.erase(bs.begin()+bs.size()-1);
                                    for(int j=0;j<bs.size();j++){
                                        if(a[1][0]>a[bs[j]][0]){
                                            bs.insert(bs.begin()+j,i);
                                        }
                                    }
                                    if(bs.size()!=siz) bs.push_back(i);
                                }
                                else{
                                    if(cs.size()<n/2){
                                        for(int j=0;j<cs.size();j++){
                                            if(a[i][0]>a[cs[j]][0]){
                                                cs.insert(cs.begin()+j,i);
                                            }
                                        }
                                        if(cs.size()==siz) cs.push_back(i);
                                    }
                                    if(a[i][0]>cs[cs.size()-1]){
                                        cs.erase(cs.begin()+cs.size()-1);
                                        for(int j=0;j<cs.size();j++){
                                            if(a[1][0]>a[cs[j]][0]){
                                                cs.insert(cs.begin()+j,i);
                                            }
                                        }
                                        if(cs.size()!=siz) cs.push_back(i);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else{
                if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
                    int siz=bs.size();
                    if(bs.size()<n/2){
                        for(int j=0;j<bs.size();j++){
                            if(a[i][0]>a[bs[j]][0]){
                                bs.insert(bs.begin()+j,i);
                            }
                        }
                        if(bs.size()==siz) bs.push_back(i);
                    }
                    else{
                        if(a[i][0]>bs[bs.size()-1]){
                            bs.erase(bs.begin()+bs.size()-1);
                            for(int j=0;j<bs.size();j++){
                                if(a[i][0]>a[bs[j]][0]){
                                    bs.insert(bs.begin()+j,i);
                                }
                            }
                            if(bs.size()!=siz) bs.push_back(i);
                        }
                        else{
                            if(a[i][0]>a[i][2]){
                                if(as.size()<n/2){
                                    for(int j=0;j<as.size();j++){
                                        if(a[i][0]>a[as[j]][0]){
                                            as.insert(as.begin()+j,i);
                                        }
                                    }
                                    if(as.size()==siz) as.push_back(i);
                                }
                                else{
                                    if(a[i][0]>as[as.size()-1]){
                                        as.erase(as.begin()+as.size()-1);
                                        for(int j=0;j<as.size();j++){
                                            if(a[1][0]>a[as[j]][0]){
                                                as.insert(as.begin()+j,i);
                                            }
                                        }
                                        if(as.size()!=siz) as.push_back(i);
                                    }
                                    else{
                                        if(cs.size()<n/2){
                                            for(int j=0;j<cs.size();j++){
                                                if(a[i][0]>a[cs[j]][0]){
                                                    cs.insert(cs.begin()+j,i);
                                                }
                                            }
                                            if(cs.size()==siz) cs.push_back(i);
                                        }
                                        if(a[i][0]>cs[cs.size()-1]){
                                            cs.erase(cs.begin()+cs.size()-1);
                                            for(int j=0;j<cs.size();j++){
                                                if(a[1][0]>a[cs[j]][0]){
                                                    cs.insert(cs.begin()+j,i);
                                                }
                                            }
                                            if(cs.size()!=siz) cs.push_back(i);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else{
                    int siz=cs.size();
                    if(cs.size()<n/2){
                        for(int j=0;j<cs.size();j++){
                            if(a[i][0]>a[cs[j]][0]){
                                cs.insert(cs.begin()+j,i);
                            }
                        }
                        if(cs.size()==siz) cs.push_back(i);
                    }
                    else{
                        if(a[i][0]>cs[cs.size()-1]){
                            cs.erase(cs.begin()+cs.size()-1);
                            for(int j=0;j<cs.size();j++){
                                if(a[i][0]>a[cs[j]][0]){
                                    cs.insert(cs.begin()+j,i);
                                }
                            }
                            if(cs.size()!=siz) cs.push_back(i);
                        }
                        else{
                            if(a[i][0]>a[i][1]){
                                if(as.size()<n/2){
                                    for(int j=0;j<as.size();j++){
                                        if(a[i][0]>a[as[j]][0]){
                                            as.insert(as.begin()+j,i);
                                        }
                                    }
                                    if(as.size()==siz) as.push_back(i);
                                }
                                else{
                                    if(a[i][0]>as[as.size()-1]){
                                        as.erase(as.begin()+as.size()-1);
                                        for(int j=0;j<as.size();j++){
                                            if(a[1][0]>a[as[j]][0]){
                                                as.insert(as.begin()+j,i);
                                            }
                                        }
                                        if(as.size()!=siz) as.push_back(i);
                                    }
                                    else{
                                        if(bs.size()<n/2){
                                            for(int j=0;j<bs.size();j++){
                                                if(a[i][0]>a[bs[j]][0]){
                                                    bs.insert(bs.begin()+j,i);
                                                }
                                            }
                                            if(bs.size()==siz) bs.push_back(i);
                                        }
                                        if(a[i][0]>bs[bs.size()-1]){
                                            bs.erase(bs.begin()+bs.size()-1);
                                            for(int j=0;j<bs.size();j++){
                                                if(a[1][0]>a[bs[j]][0]){
                                                    bs.insert(bs.begin()+j,i);
                                                }
                                            }
                                            if(bs.size()!=siz) bs.push_back(i);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int p=0;
        for(int j=0;j<as.size();j++){
            p+=as[j];
        }
        for(int j=0;j<bs.size();j++){
            p+=bs[j];
        }
        for(int j=0;j<cs.size();j++){
            p+=cs[j];
        }
    }
}
